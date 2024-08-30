#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cmath>

// modelar la particula
class Particle {
public: 
  std::vector<double> R{0.0, 0.0, 0.0}, V{0.0, 0.0, 0.0}, F{0.0, 0.0, 0.0};
  double mass = 1.0, rad = 0.17;

  Particle(){}; // constructor
  ~Particle(){}; // destructor
};

void initial_conditions(std::vector<Particle> & particles);
void compute_forces(std::vector<Particle> & particles, std::map<std::string, double> &params);
void start_time_integration(std::vector<Particle> & particles, std::map<std::string, double> &params);
void time_step(std::vector<Particle> & particles, std::map<std::string, double> &params);
void print_gnuplot(const std::vector<Particle> & particles, std::map<std::string, double> &params, double time);
void print_paraview(const std::vector<Particle> & particles, std::map<std::string, double> &params, int iter, double time);

int main(int argc, char *argv[]) {
  const int N = 1;
  std::vector<Particle> particles{N};

  // parametros
  std::map<std::string, double> PARAMS;
  PARAMS["G"] = 9.81; // Gravity module, m/s^2
  PARAMS["K"] = 2000.4567; // Elastic constant, N/m
  PARAMS["B"] = 0.0; // Damping strength, 1/s
  PARAMS["CIRCLE_RADIUS"] = 1.0; // Radio del círculo
  PARAMS["CIRCLE_CENTER_X"] = 1.0; // Centro del círculo en X
  PARAMS["CIRCLE_CENTER_Z"] = 1.0; // Centro del círculo en Y
  PARAMS["DT"] = 0.001; // Time step size, s
  PARAMS["T0"] = 0.0; // Initial time, s
  PARAMS["TF"] = 2.3456; // Final time, s 
  PARAMS["NSTEPS"] = int((PARAMS["TF"]-PARAMS["T0"])/PARAMS["DT"]); // [-]


  // condiciones iniciales
  initial_conditions(particles);
  compute_forces(particles, PARAMS);
  start_time_integration(particles, PARAMS);

  // temporal loop
  for (int istep = 0; istep <= PARAMS["NSTEPS"]; ++istep) {
    compute_forces(particles, PARAMS);
    time_step(particles, PARAMS);
    double time = PARAMS["T0"] + istep*PARAMS["DT"];
    print_gnuplot(particles, PARAMS, time);
    print_paraview(particles, PARAMS, istep, time);
  }

  return 0;
}

void initial_conditions(std::vector<Particle> & particles) {
  // condiciones iniciales
  particles[0].mass = 1.987;
  particles[0].rad =  0.1765;
  particles[0].R[0] = 1.0; // X
  particles[0].R[2] = 1.0; // Z
  particles[0].V[2] = +3.21323432; // Velocidad en Z
  particles[0].V[0] = 3.0; // Velocidad en X
}

void compute_forces(std::vector<Particle> &particles, std::map<std::string, double> &params) {
  // reset forces
  for (auto & body : particles) {
    for (int ii = 0; ii < 3; ii++) {
      body.F[ii] = 0.0;
    }
  }
  // Add gravitational forces
  for (auto & body : particles) {
    body.F[2] -= body.mass*params["G"];
  }
  // Add damping vertical force
  for (auto & body : particles) {
    body.F[2] -= body.mass*params["B"]*body.V[2];
  }
  // Force against the circular boundary
  for (auto & body : particles) {
    double dx = body.R[0] - params["CIRCLE_CENTER_X"];
    double dz = body.R[2] - params["CIRCLE_CENTER_Z"];
    double distance_to_center = std::sqrt(dx*dx + dz*dz);
    double delta = distance_to_center + body.rad - params["CIRCLE_RADIUS"];
    if (delta >= 0) {
      double force_magnitude = params["K"] * delta;
      body.F[0] -= force_magnitude * (dx / distance_to_center); //normalizar el vector de fuerza
      body.F[2] -= force_magnitude * (dz / distance_to_center); 
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
  // leap-frog
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
    std::cout << body.mass << " " << body.R[0] << " " << body.R[1] << " " << body.R[2] << " " 
              << body.V[0] << " " << body.V[1] << " " << body.V[2] << " " 
              << body.F[0] << " " << body.F[1] << " " << body.F[2] << " ";
  }
  std::cout << "\n";
}

void print_paraview(const std::vector<Particle> &particles,
           std::map<std::string, double> &params, int iter, double time) {
  // creates a file per time step
  
  // set the filename: datos-{istep}.txt
  std::string fname = "DISPLAY/datos-" + std::to_string(iter) + ".txt";  
  
  // open the file
  std::ofstream fout(fname);
  
  // write data
  fout << time << " ";
  for (const auto & body : particles) {
    fout << body.mass << " " ;
    for (int ii = 0; ii < 3; ii++) {
      fout << body.R[ii] << " " << body.V[ii] << " " << body.F[ii] << " ";
    }
  }
  fout << "\n";
  // close the file
  fout.close();
}
