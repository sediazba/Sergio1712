#include <iostream>
#include <vector>
#include <string>
#include <map>

// Modelar la partícula
class Particle {
public:
    double Rz = 0.0, Fz = 0.0;
    double mass = 1.0;
    double prev_Rz = 0.0; // Variable para almacenar la posición anterior
    double Vz = 0.0; // Velocidad inicial

    Particle() {}; // Constructor
    ~Particle() {}; // Destructor
};

void initial_conditions(std::vector<Particle>& particles);
void compute_forces(std::vector<Particle>& particles, std::map<std::string, double>& params);
void start_time_integration(std::vector<Particle>& particles, std::map<std::string, double>& params);
void time_step(std::vector<Particle>& particles, std::map<std::string, double>& params);
void print(const std::vector<Particle>& particles, std::map<std::string, double>& params, double time);

int main(int argc, char* argv[]) {
    const int N = 1;
    std::vector<Particle> particles(N);

    // Parámetros
    std::map<std::string, double> PARAMS;
    PARAMS["G"] = 9.81;
    PARAMS["DT"] = 0.01;
    PARAMS["T0"] = 0.0;
    PARAMS["TF"] = 2.3456;
    PARAMS["NSTEPS"] = int((PARAMS["TF"] - PARAMS["T0"]) / PARAMS["DT"]);

    // Condiciones iniciales
    initial_conditions(particles);
    compute_forces(particles, PARAMS);
    start_time_integration(particles, PARAMS);

    // Bucle temporal
    for (int istep = 0; istep <= PARAMS["NSTEPS"]; ++istep) {
        time_step(particles, PARAMS);
        compute_forces(particles, PARAMS);
        print(particles, PARAMS, PARAMS["T0"] + istep * PARAMS["DT"]);
    }

    return 0;
}

void initial_conditions(std::vector<Particle>& particles) {
    // Condiciones iniciales
    particles[0].mass = 1.987;
    particles[0].Rz = 1.21;
    particles[0].Vz = 3.21; // Velocidad inicial no nula
}

void compute_forces(std::vector<Particle>& particles, std::map<std::string, double>& params) {
    // Resetear fuerzas
    for (auto& body : particles) {
        body.Fz = 0.0;
    }
    // Añadir fuerza gravitacional
    for (auto& body : particles) {
        body.Fz -= body.mass * params["G"];
    }
}

void start_time_integration(std::vector<Particle>& particles, std::map<std::string, double>& params) {
    for (auto& body : particles) {
        // Primera estimación de la posición anterior usando la velocidad inicial
        body.prev_Rz = body.Rz - body.Vz * params["DT"] + 0.5 * params["DT"] * params["DT"] * body.Fz / body.mass;
    }
}

void time_step(std::vector<Particle>& particles, std::map<std::string, double>& params) {
    for (auto& body : particles) {
        double new_Rz = 2 * body.Rz - body.prev_Rz + params["DT"] * params["DT"] * body.Fz / body.mass;
        body.prev_Rz = body.Rz;
        body.Rz = new_Rz;
    }
}

void print(const std::vector<Particle>& particles, std::map<std::string, double>& params, double time) {
    std::cout << time << " ";
    for (const auto& body : particles) {
        std::cout << body.mass << "\t" << body.Rz << "\t" << body.Vz << "\t" << body.Fz << "\t";
    }
    std::cout << "\n";
}
