#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "vectors.h"


int main(int argc, char** argv)
{
    //¿argc >2?
    const int N = std::stoi(argv[1]);
    //crear 2 vectores
    std::vector <double> x(N), y(N);
    //llenar los vectores
    //forma 1: Indices
    for(int ii = 0; ii < N; ++ii) {
        x[ii] = 1.0;
        y[ii] = 1.0;
    }
    //forma 2: auto val & (porque vamos a cambiar los datos)(individualmente)
    for (auto & val : x) {
        val = 1.0;
    }
    for (auto & val : x) {
        val = 1.0;
    }
    //forma 3: 
    std::fill(x.begin(), x.end(), 1.0);
    std::fill(y.begin(), y.end(), 1.0);
    //forma 4:
    x.assign(N, 1.0);
    y.assign(N, 1.0);
    //forma 5:
    std::generate(x.begin(), x.end(), [](void){ return 1.0; } );
    std::generate(x.begin(), x.end(), [](void){ return 1.0; } ); //una lambda
    //forma 6:random
    int seed = 0;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(1.0, 2.0);
    std::generate(x.begin(), x.end(), [&dis, &gen](void){ return dis(gen); } );
    std::generate(x.begin(), x.end(), [&dis, &gen](void){ return dis(gen); } ); //una lambda

    //Calcular e imprimir el producto punto
    double dot_value = dot(x, y);
    std::cout << dot_value << "\n";
    return 0;
}