#include <iostream>
#include <vector>
#include <string>

template <typename T>
double sacar_minimo(const std::vector <T> & v1);

int main(int argc, char** argv)
{
    std::vector<double> v1(argc - 1); //cantidad de numeros insertados incluido el ./a.out por eso se resta 1

    for(int i = 1; i < argc; i = i + 1){
        v1[i - 1] = std::stod(argv[i]);
    }

    std::cout << sacar_minimo(v1) << "\n";
    return 0;
}

template <typename T>
double sacar_minimo(const std::vector <T> & v1)
{
    double minimo = v1[0];
    for(auto val : v1){
        if(val < minimo){
            minimo = val;
        }
    }
    /*for(int ii = 0; ii < v1.size(); ii = ii + 1){
        if(v1[ii] < minimo){
            minimo = v1[ii];
        }
    }*/
    return minimo;
}
