#include <iostream>
#include <cmath>
#include <valarray>
#include <random>

int main(void)
{
    std::valarray<int> v(5);
    int seed = 0;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(1000, 2500);

    for(int ii = 0; ii < v.size(); ii = ii + 1){
        v[ii] = dis(gen);
    }

    std::valarray<bool> par = (v % 2 == 0);

    // Contar el número de elementos pares
    int count = par.sum();

    // Crear un valarray para los elementos pares
    std::valarray<int> v2(count);

    // Copiar los elementos pares a v2
    int index = 0;
    for (int ii = 0; ii < v.size(); ++ii) {
        if (par[ii]) {
            v2[index++] = v[ii];
        }
    }

    for(auto n : v){
        std::cout << n << "\t";
    }
    std::cout << "\n";

    for(auto n : v2){
        std::cout << n << "\t";
    }
    std::cout << "\n";
}