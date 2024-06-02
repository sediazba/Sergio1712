#include <iostream>
#include <string>
#include <vector>
#include <cmath>

template <typename T>
double Norm_vector(const std::vector <T> & v1);

int main(int argc, char** argv)
{
    std::vector<double> v1(argc - 1); //cantidad de numeros insertados incluido el ./a.out por eso se resta 1

    for(int i = 1; i < argc; i = i + 1){
        v1[i - 1] = std::stod(argv[i]);
    }

    std::cout << Norm_vector(v1) << "\n";
    return 0;
}

template <typename T>
double Norm_vector(const std::vector <T> & v1)
{
    double suma_componentes = 0;
    for(const auto & val : v1){
        suma_componentes = suma_componentes + std::pow(val, 2);
    }
    return std::sqrt(suma_componentes);
}