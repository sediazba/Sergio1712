#include <iostream>
#include <valarray>
#include <cmath>
#include <random>
#include <vector>

int main(int argc, char** argv)
{
    int size = std::stoi(argv[1]);
    std::valarray<double> v1(size);
    std::valarray<double> v2(size);

    std::random_device rd;
    std::mt19937 gen(rd()); //completamente aleatorio
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int ii = 0; ii < size; ii = ii + 1) {
        v1[ii] = dis(gen);
        v2[ii] = dis(gen);
    }

    double suma = 0;

    for(int ii = 0; ii < v1.size(); ii = ii + 1){
        suma = suma + v1[ii]*v2[ii];
    }

    for(auto n : v1){std::cout << v1[n] << "\t";}
    std::cout << "\n";

    for(auto n : v2){std::cout << v1[n] << "\t";}
    std::cout << "\n";

    std::cout << suma << "\n";
}