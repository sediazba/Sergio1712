#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <vector>

// modelar la particula
class Particle {
public: //visibilidad de todo lo que está debajo, se le puede meter la mano a la clase
	std::vector<double> R{0.0, 0.0, 0.0};
	std::vector<double> V{0.0, 0.0, 0.0};
	std::vector<double> F{0.0, 0.0, 0.0};
	double mass = 1.0;

  	Particle(){}; //constructor
  	~Particle(){}; //destructor
};

void initial_conditions(std::vector<Particle> & particles); //El tipo de dato es Particle porque cada componente del vector tiene Rz, Vz, Fz y mass
void compute_forces(std::vector<Particle> & particles, std::map<std::string, double> &params);
void start_time_integration(std::vector<Particle> & particles, std::map<std::string, double> &params);
void time_step(std::vector<Particle> & particles, std::map<std::string, double> &params);
void print(const std::vector<Particle> & particles, std::map<std::string, double> &params, double time);

int main(int argc, char *argv[]) {
  const int N = 1;
  std::vector<Particle> particles(N);

  // parametros
  std::map<std::string, double> PARAMS;
  PARAMS["G"] = 9.81;
  PARAMS["B"] = 1.81;
  PARAMS["DT"] = 0.01;
  PARAMS["T0"] = 0.0;
  PARAMS["TF"] = 2.3456;
  PARAMS["NSTEPS"] = int((PARAMS["TF"]-PARAMS["T0"])/PARAMS["DT"]);


  // condiciones iniciales
  initial_conditions(particles);
  compute_forces(particles, PARAMS);
  start_time_integration(particles, PARAMS);

  // temporal loop
  for (int istep = 0; istep <= PARAMS["NSTEPS"]; ++istep) {
	  compute_forces(particles, PARAMS);
	  time_step(particles, PARAMS);
	  print(particles, PARAMS, PARAMS["T0"] + istep*PARAMS["DT"]);
  }
  return 0;
}

void initial_conditions(std::vector<Particle> & particles) {
  // condiciones iniciales
  	particles[0].mass = 1.987;
	particles[0].R[2] = 1.21;
	particles[0].V[2] = 3.21;
}


void compute_forces(std::vector<Particle> &particles, std::map<std::string, double> &params) {
	// reset forces
	for (auto & body : particles) {
		for(int ii=0; ii<=2; ii++){
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
}

void start_time_integration(std::vector<Particle> &particles, std::map<std::string, double> &params) {
	for (auto & body : particles) {
		for(int ii = 0; ii <= 2; ii++){
	  		body.V[ii] = body.V[ii] - 0.5*params["DT"]*body.F[ii]/body.mass;  // v = v_0 - 0.5*dt*aceleration
		}
	}
}

void time_step(std::vector<Particle> &particles, std::map<std::string, double> &params){
	// leap-frog
	for (auto & body : particles) {
		for(int ii=0; ii<=2; ii++){
			body.V[ii] = body.V[ii] + params["DT"]*body.F[ii]/body.mass;
			body.R[ii] = body.R[ii] + params["DT"]*body.V[ii];
		}
	}
}


void print(const std::vector<Particle> &particles,
    std::map<std::string, double> &params, double time) {
	std::cout << time << " ";
	for (const auto & body : particles) {
	  	std::cout << body.mass << "\t";
		for(int ii=0; ii<=2; ii++){
			std::cout << body.R[ii] << "\t" << body.V[ii] << "\t" << body.F[ii] << "\t";
		}
	}
	std::cout << "\n";
}
