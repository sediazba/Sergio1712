#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>

int main(int argc, char** argv)
{
    const int N = std::stoi(argv[1]);
    std::vector <double> x(N);
    std::vector <double> y(N);
    std::vector <double> z(N);
    std::vector <double> a(N);
    std::vector <double> b(N);
    std::vector <double> c(N);
    std::vector <double> d(N);

    int seed = 0;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> uniform_dis(1.0, 10.0);
    std::generate(x.begin(), x.end(), [&uniform_dis, &gen](void){ return uniform_dis(gen); } );

    std::exponential_distribution<> exp_dis(4);
    std::generate(y.begin(), y.end(), [&exp_dis, &gen](void){ return exp_dis(gen); } );

    std::weibull_distribution<> weibull_dis(1.0, 8.0);
    std::generate(z.begin(), z.end(), [&weibull_dis, &gen](void){ return weibull_dis(gen); } );

    std::normal_distribution<> normal_dis(1.0, 3.0);
    std::generate(a.begin(), a.end(), [&normal_dis, &gen](void){ return normal_dis(gen); } );

    std::gamma_distribution<> gamma_dis(1.0, 8.0);
    std::generate(b.begin(), b.end(), [&gamma_dis, &gen](void){ return gamma_dis(gen); } );

    std::lognormal_distribution<> log_dis(1.0, 3.0);
    std::generate(c.begin(), c.end(), [&log_dis, &gen](void){ return log_dis(gen); } );

    std::cauchy_distribution<> cauchy_dis(1.0, 3.0);
    std::generate(d.begin(), d.end(), [&cauchy_dis, &gen](void){ return cauchy_dis(gen); } );

    for(int ii = 0; ii < N; ii = ii +1){
        std::cout << x[ii] << "\t\t";
    }
    std::cout << "\n";

    for(int ii = 0; ii < N; ii = ii +1){
        std::cout << y[ii] << "\t";
    }
    std::cout << "\n";

    for(int ii = 0; ii < N; ii = ii +1){
        std::cout << z[ii] << "\t\t";
    }
    std::cout << "\n";
    
    for(int ii = 0; ii < N; ii = ii +1){
        std::cout << a[ii] << "\t";
    }
    std::cout << "\n";

    for(int ii = 0; ii < N; ii = ii +1){
        std::cout << b[ii] << "\t";
    }
    std::cout << "\n";

    for(int ii = 0; ii < N; ii = ii +1){
        std::cout << c[ii] << "\t";
    }
    std::cout << "\n";

    for(auto val : d){
        std::cout << val << "\t";
    }
    std::cout << "\n";

    return 0;
}