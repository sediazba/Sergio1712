#include "derivadas.h"
#include <iostream>

int main(int argc, char** argv)
{
    double x = std::stod(argv[1]);

    double derivada_real = 2 * x * std::cos(x*x);

    for(int i = -10; i < 1; i = i + 1){
        double h = std::pow(10.0, i);
        std::cout << h << "\t" << std::fabs(1 - (forward_deriv(x, h, function)/derivada_real)) << "\t" << std::fabs(1 - (central_deriv(x, h, function)/derivada_real)) << "\t" <<
                    std::fabs(1 - (richardson_deriv(x, h, forward_deriv, 1)/derivada_real)) << "\t" << std::fabs(1 - (richardson_deriv(x, h, central_deriv, 2)/derivada_real)) << "\n";
    }
    return 0;
}

