#include "integrales.h"
#include <iostream>

int main(int argc, char** argv)
{
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);

    double valor_real = std::erf(1);
    
    for(int ii = 0; ii < 8; ii = ii + 1){
        double N = std::pow(10.0, ii);
        std::cout.precision(10);
        std::cout << N << "\t"  << std::fabs(1 - (trapezoid(a, b, N, function)/valor_real)) << "\t" << std::fabs(1 - (simpson(a, b, N, function)/valor_real)) << "\t" << 
	    std::fabs(1 - (richardson(a, b, N, trapezoid, function, 2)/valor_real)) << "\t" << std::fabs(1 - (richardson(a, b, N, simpson, function, 4)/valor_real)) << "\t" <<
        std::fabs(1 - (gauss_5(a, b, function)/valor_real)) << "\n";
    }
    /*std::cout << std::erf(1) << "\t" << trapezoid(a, b, N, function) << "\t" << simpson(a, b, N, function) << "\t" << richardson(a, b, N, trapezoid, function, 2) <<
            "\t" << richardson(a, b, N, simpson, function, 4) << "\n";*/

    return 0; 
}
