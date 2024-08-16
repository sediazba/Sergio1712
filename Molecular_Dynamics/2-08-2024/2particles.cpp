#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath> // Para usar sqrt
#include <fstream>

// Modelar la partícula
class Particle {
public: 
  std::vector<double> R{0.0, 0.0, 0.0}, V{0.0, 0.0, 0.0}, F{0.0, 0.0, 0.0};
  double mass = 1.0, rad = 0.17;

  Particle(){}; // Constructor
  ~Particle(){}; // Destructor
};

void initial_conditions(std::vector<Particle> & particles);
void compute_forces(std::vector<Particle> & particles, std::map<std::string, double> &params);
void start_time_integration(std::vector<Particle> & particles, std::map<std::string, double> &params);
void time_step(std::vector<Particle> & particles, std::map<std::string, double> &params);
void print_gnuplot(const std::vector<Particle> & particles, std::map<std::string, double> &params, double time);
void print_paraview(const std::vector<Particle> & particles, std::map<std::string, double> &params, int iter, double time);

int main(int argc, char *argv[]) {
  const int N = 2; // Cambiado a 2 para agregar otra partícula
  std::vector<Particle> particles(N);

  // Parámetros
  std::map<std::string, double> PARAMS;
  PARAMS["G"] = 9.81; // Gravedad, m/s^2
  PARAMS["K"] = 8230.4567; // Constante elástica, N/m
  PARAMS["B"] = 0.0; // Amortiguamiento, 1/s
  PARAMS["WRX"] = 4.9786; // Pared derecha, m
  PARAMS["WLX"] = 0.0; // Pared izquierda, m
  PARAMS["DT"] = 0.001; // Tamaño del paso de tiempo, s
  PARAMS["T0"] = 0.0; // Tiempo inicial, s
  PARAMS["TF"] = 0.9456; // Tiempo final, s 
  PARAMS["NSTEPS"] = int((PARAMS["TF"]-PARAMS["T0"])/PARAMS["DT"]); // Número de pasos

  // Condiciones iniciales
  initial_conditions(particles);
  compute_forces(particles, PARAMS);
  start_time_integration(particles, PARAMS);

  // Bucle temporal
  for (int istep = 0; istep <= PARAMS["NSTEPS"]; ++istep) {
    compute_forces(particles, PARAMS);
    time_step(particles, PARAMS);
    double time = PARAMS["T0"] + istep*PARAMS["DT"];
    print_gnuplot(particles, PARAMS, time);
    //if (istep % 20 == 0) {
    //  print_paraview(particles, PARAMS, istep, time);
    //}
  }
  return 0;
}

void initial_conditions(std::vector<Particle> & particles) {
  // Condiciones iniciales para la primera partícula
  particles[0].mass = 1.987;
  particles[0].rad =  0.1765;
  particles[0].R[2] = 2.0;
  particles[0].V[2] = 2.0;
  particles[0].R[0] = 0.1;
  particles[0].V[0] = +1.87654;

  // Condiciones iniciales para la segunda partícula
  particles[1].mass = 1.987;
  particles[1].rad = 0.1765;
  particles[1].R[2] = 2.0;
  particles[1].V[2] = 2.0;
  particles[1].R[0] = 4.9;
  particles[1].V[0] = -1.87654;
}

void compute_forces(std::vector<Particle> &particles, std::map<std::string, double> &params) {
  // Reiniciar fuerzas
  for (auto & body : particles) {
    for (int ii = 0; ii < 3; ii++) {
      body.F[ii] = 0.0;
    }
  }
  // Añadir fuerzas gravitacionales
  for (auto & body : particles) {
    body.F[2] -= body.mass*params["G"];
  }
  // Añadir fuerza de amortiguamiento vertical
  for (auto & body : particles) {
    body.F[2] -= body.mass*params["B"]*body.V[2];
  }
  // Fuerza contra el suelo
  for (auto & body : particles) {
    double delta = body.rad - body.R[2];
    if (delta >= 0) {
      body.F[2] += params["K"]*delta;
    }
  }
  // Fuerza contra la pared derecha
  for (auto & body : particles) {
    double delta = body.rad + body.R[0] - params["WRX"];
    if (delta >= 0) {
      body.F[0] -= params["K"]*delta;
    }
  }
  // Fuerza contra la pared izquierda
  for (auto & body : particles) {
    double delta = +body.rad - body.R[0] + params["WLX"];
    if (delta >= 0) {
      body.F[0] += params["K"]*delta;
    }
  }

  // Calcular la fuerza de interacción entre las partículas
  for (int ii = 0; ii < particles.size(); ii = ii + 1) {
    for (int jj = ii + 1; jj < particles.size(); jj = jj + 1) {
      std::vector<double> Rij(3);
      double dist = 0.0;
      for (int k = 0; k < 3; k = k + 1) {
        Rij[k] = particles[jj].R[k] - particles[ii].R[k];
        dist += Rij[k] * Rij[k];
      }
      dist = sqrt(dist);
      double delta = particles[ii].rad + particles[jj].rad - dist;
      if (delta >= 0) {
        for (int k = 0; k < 3; ++k) {
          double Fij = params["K"] * delta * (Rij[k] / dist);
          particles[ii].F[k] -= Fij;
          particles[jj].F[k] += Fij;
        }
      }
    }
  }
}

void start_time_integration(std::vector<Particle> &particles,
                            std::map<std::string, double> &params) {
  for (auto & body : particles) {
    for (int ii = 0; ii < 3; ii++) {
      body.V[ii] = body.V[ii] - 0.5*params["DT"]*body.F[ii]/body.mass;
    }
  }
}


void time_step(std::vector<Particle> &particles,
               std::map<std::string, double> &params) {
  // Método leap-frog
  for (auto & body : particles) {
    for (int ii = 0; ii < 3; ii++) {
      body.V[ii] = body.V[ii] + params["DT"]*body.F[ii]/body.mass;
      body.R[ii] = body.R[ii] + params["DT"]*body.V[ii];
    }
  }
}

void print_gnuplot(const std::vector<Particle> &particles,
                    std::map<std::string, double> &params, double time) {
  std::cout << time << " ";
  for (const auto & body : particles) {
    std::cout << body.mass << " ";
    std::cout << body.rad << " ";
    for (int ii = 0; ii < 3; ++ii) {
      std::cout << body.R[ii] << " ";
    }
    for (int ii = 0; ii < 3; ++ii) {
      std::cout << body.V[ii] << " ";
    }
    for (int ii = 0; ii < 3; ++ii) {
      std::cout << body.F[ii] << " ";
    }
  }
  std::cout << "\n";
}


void print_paraview(const std::vector<Particle> &particles,
           std::map<std::string, double> &params, int iter, double time) {
  // Crea un archivo por cada paso de tiempo
  
  // Establecer el nombre del archivo: DISPLAY/datos-{istep}.txt
  std::string fname = "DISPLAY/datos-" + std::to_string(iter) + ".csv";  
  
  // Abrir el archivo
  std::ofstream fout(fname);

  // Escribir encabezado
  fout << "Rx, Ry, Rz, Vx, Vy, Vz, Fx, Fy, Fz, mass, rad\n"; 
  
  // Escribir datos
  for (const auto & body : particles) {
    fout << body.R[0] << ", " << body.R[1] << ", " << body.R[2] << ", ";
    fout << body.V[0] << ", " << body.V[1] << ", " << body.V[2] << ", ";
    fout << body.F[0] << ", " << body.F[1] << ", " << body.F[2] << ", ";
    fout << body.mass << ", " << body.rad << "\n";
  }
  
  fout.close();
}
