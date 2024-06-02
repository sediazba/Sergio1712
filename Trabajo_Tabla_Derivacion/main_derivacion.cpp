#include <iostream>
#include "derivacion.h"
#include <fstream>

long double fun(long double x);

int main(int argc, char **argv)
{
    long double x = M_PI/2;
    long double valor_exacto = ((2 * ((x * std::cos(x)) - std::sin(x)))/(x*x)); //valor real de la derivada de lafunción
    std::ofstream outf{"derivaties.txt"};
    outf.precision(15);
    outf.setf(std::ios::scientific);
    //tablealg_diff es la derivada siguiendo los valores de la tabla, rich_diff es ella misma con la extrapolacion de Richardson
    for (double h = 10e-16; h <= 1; h = h*10) {
        outf << h << "  " << std::fabs(valor_exacto - tablealg_diff(x, h, 1.0, 0, 0, 1.0/2, 0, 0, fun))<< "  "
                << std::fabs(valor_exacto - tablealg_diff(x, h, 1.0/2, 0, 0, 1.0, 0, 0, fun))<< "  "
                << std::fabs(valor_exacto - tablealg_diff(x, h, -1.0/24, 27.0/24, 0, 3.0/2, 1.0/2, 0, fun))<< "  "
                << std::fabs(valor_exacto - tablealg_diff(x, h, -1.0/12, 2.0/3, 0, 2.0, 1.0, 0, fun))<< "  "
                << std::fabs(valor_exacto - tablealg_diff(x, h, 3.0/640, -25.0/384, 75.0/64, 5.0/2, 3.0/2, 1.0/2, fun)) << "  "
                << std::fabs(valor_exacto - rich_diff(x, h, 1.0, 0, 0, 1.0/2, 0, 0, fun, tablealg_diff, 2)) << "  "
                << std::fabs(valor_exacto - rich_diff(x, h, 1.0/2, 0, 0, 1.0, 0, 0, fun, tablealg_diff, 2)) << "  "
                << std::fabs(valor_exacto - rich_diff(x, h, -1.0/24, 27.0/24, 0, 3.0/2, 1.0/2, 0, fun, tablealg_diff, 4)) << "  "
                << std::fabs(valor_exacto - rich_diff(x, h, -1.0/12, 2.0/3, 0, 2.0, 1.0, 0, fun, tablealg_diff, 4)) << "  "
                << std::fabs(valor_exacto - rich_diff(x, h, 3.0/640, -25.0/384, 75.0/64, 5.0/2, 3.0/2, 1.0/2, fun, tablealg_diff, 6)) << "\n";
    }
    outf.close();
    return 0;
}
//funcion a derivar
long double fun(long double x)
{
    long double b = ((2 * std::sin(x))/x);
    return b;
}
