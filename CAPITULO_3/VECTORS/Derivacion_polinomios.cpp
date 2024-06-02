#include <iostream>
#include <vector>
#include <string>

template <typename T>
double derivacion_polinomios(const std::vector<T> & v1);

int main(int argc, char** argv)
{
    std::vector<double> v1(argc - 1); //cantidad de numeros insertados incluido el ./a.out por eso se resta 1
    std::vector<double> derivada(argc - 2);

    for(int i = 1; i < argc; i = i + 1){
        v1[i - 1] = std::stod(argv[i]);
    }

    for(int ii = 1; ii <= v1.size(); ii = ii + 1){
        derivada[ii - 1] = ii*v1[ii];
    }

    for(int i = 0; i < v1.size(); i = i + 1){
        std::cout << v1[i] << "\t";
    }

    std::cout << "\n\n";

    for(int i = 0; i < derivada.size(); i = i + 1){
        std::cout << derivada[i] << "\t";
    }

    std::cout << "\n";

    return 0;
}
