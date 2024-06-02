#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <cmath>

int main(int argc, char** argv)
{
    int N = std::stoi(argv[1]);
    std::vector <int> x(N);
    std::vector <int> y(N);
    std::vector <int> z(N);

    int seed = 0;
    std::mt19937 gen(seed);
    std::poisson_distribution<> poisson_dis(6.0);
    std::generate(x.begin(), x.end(), [&poisson_dis, &gen](void){ return poisson_dis(gen); } );

    std::binomial_distribution<> binomial_dis(2.0, 0.5);
    std::generate(y.begin(), y.end(), [&binomial_dis, &gen](void){ return binomial_dis(gen); } );

    std::geometric_distribution<> geo_dis(0.5);
    std::generate(z.begin(), z.end(), [&geo_dis, &gen](void){ return geo_dis(gen); } );

    for(int i = 0; i < N; i = i + 1){
        std::cout << x[i] << "\t";
    }
    std::cout<< "\n";

    std::shuffle(x.begin(), x.end(), gen);
    for(int i = 0; i < N; i = i + 1){
        std::cout << x[i] << "\t";
    }
    std::cout<< "\n\n";

    for(int i = 0; i < N; i = i + 1){
        std::cout << y[i] << "\t";
    }
    std::cout<< "\n";

    std::shuffle(y.begin(), y.end(), gen);
    for(int i = 0; i < N; i = i + 1){
        std::cout << y[i] << "\t";
    }
    std::cout<< "\n\n";

    for(int i = 0; i < N; i = i + 1){
        std::cout << z[i] << "\t";
    }
    std::cout<< "\n";

    std::shuffle(z.begin(), z.end(), gen);
    for(int i = 0; i < N; i = i + 1){
        std::cout << z[i] << "\t";
    }
    std::cout<< "\n";
    return 0;
}