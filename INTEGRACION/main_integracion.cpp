#include <fstream>
#include <iostream>
#include <cmath>
#include "integracion.h"

double fun(double x);
void test_integ1(void); //Funcion que harala impresion "revision"

int main(void)
{
    test_integ1();

    return 0; 
}

double fun(double x)
{
    return 2*std::exp(-std::pow(x,2))/std::sqrt(M_PI);
}

void test_integ1(void)
{

    double upper_limit = 0.54432;
    double exact = std::erf(upper_limit); // valor exacto de la integral

    std::ofstream outf{"integracion.txt"};

    outf.precision(16);
    outf.setf(std::ios::scientific);

    for(double ii = 1.0; ii < 9.0; ii++)
    {
        double npoints = std::pow(10.0,ii);

        double simp = simpson(0.0, upper_limit, npoints, fun);
        double trap = trapezoid(0.0, upper_limit, npoints, fun);
        double rich_si = rich_inte(0.0, upper_limit, npoints, fun, simpson, 1);
        double rich_tr = rich_inte(0.0, upper_limit, npoints, fun, trapezoid, 1);

        outf << npoints << "\t"
        << std::fabs(1.0 - simp/exact)<< "\t"
        << std::fabs(1.0 - trap/exact)<< "\t"
        << std::fabs(1.0 - rich_si/exact)<< "\t"
        << std::fabs(1.0 - rich_tr/exact)<< "\n";

        outf.flush();
    }
    outf.close();
}