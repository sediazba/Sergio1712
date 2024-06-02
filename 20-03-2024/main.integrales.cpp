#include <iostream>
#include "integrales.h"
#include <cmath>
#include <fstream>

double fun(double x);

int main(void)
{
    double valor_exacto = std::erf(0.54432);
    std::ofstream outf{"integrales.txt"};
    outf.precision(15);
    outf.setf(std::ios::scientific);
    for(int n = 1; n <= 9; n = n + 1){
        double k = std::pow(10.0, n);
        outf << k << "\t" << std::fabs(valor_exacto  - simpson(0.0, 0.54432, k, fun)) << "\t"
        << std::fabs(1 - ((trapezoid(0.0, 0.54432, k, fun))/valor_exacto)) << "\t"
        << std::fabs(1 - ((rich_intr(0.0, 0.54432, k, fun, trapezoid, 1))/valor_exacto)) << "\t"
        << std::fabs(1 - ((rich_intr(0.0, 0.54432, k, fun, simpson, 3))/valor_exacto)) << "\n";
    }
    outf.close();
    return 0;
}

double fun(double x)
{
    double f = ((2/std::sqrt(M_PI))*(std::pow(M_E, -(x*x))));
    return f;
}