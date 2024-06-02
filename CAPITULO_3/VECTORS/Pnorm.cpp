#include <iostream>
#include <string>
#include <vector>
#include <cmath>

template <typename T>
double Norm_vector(const std::vector <T> & v1, int P);

int main(int argc, char** argv)
{
    int P = std::stoi(argv[1]);
    std::vector<double> v1(argc - 2); //cantidad de numeros insertados incluido el ./a.out por eso se resta 1

    for(int i = 0; i < argc - 2; i = i + 1){
        v1[i] = std::stod(argv[i + 2]);
    }

    std::cout << Norm_vector(v1, P) << "\n";
    return 0;
}

template <typename T>
double Norm_vector(const std::vector <T> & v1, int P)
{
    double suma_componentes = 0;
    for(const auto & val : v1){
        suma_componentes = suma_componentes + std::pow(val, P);
    }
    return std::pow(suma_componentes, 1.0/P);
}