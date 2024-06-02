#include <iostream>
#include <vector>
#include <string>

template <typename T>
int sacar_indice_maximo(const std::vector <T> & v1);

int main(int argc, char** argv)
{
    std::vector<double> v1(argc - 1); //cantidad de numeros insertados incluido el ./a.out por eso se resta 1

    for(int i = 1; i < argc; i = i + 1){
        v1[i - 1] = std::stod(argv[i]);
    }

    std::cout << sacar_indice_maximo(v1) << "\n";
    return 0;
}

template <typename T>
int sacar_indice_maximo(const std::vector <T> & v1)
{
    double maximo = v1[0];
    int indice_maximo = 0;

    for(int ii = 0; ii < v1.size(); ii = ii + 1){
        if(v1[ii] > maximo){
            maximo = v1[ii];
            indice_maximo = ii;
        }
    }
    return indice_maximo;
}
