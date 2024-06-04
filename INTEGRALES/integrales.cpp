#include "integrales.h"
#include <iostream>

double function(double x)
{
    double f = ((2/std::sqrt(M_PI)) * std::pow(M_E, -x*x));
    return f;
}

double trapezoid(double a, double b, double N, fptr fun)
{
    double suma = ((fun(a) + fun(b))/2);
    double h = ((b-a)/N);
    for(double ii = 1; ii < N; ii = ii + 1){
        suma = suma + fun(a + (ii * h));
    }

    return (suma*h);
}

double simpson(double a, double b, double N, fptr fun)
{
    double suma = fun(a) + fun(b);
    double h = ((b - a)/N);
    for(int ii = 1; ii <= N; ii = ii + 2){
        suma = suma + (4 * fun(a + (ii * h)));
    }

    for(int ii = 2; ii < N; ii = ii + 2)
    {
        suma = suma + (2 * fun(a + (ii * h)));
    }

    return (h/3.0) * suma;
}

double richardson(double a, double b, double N, algptr alg, fptr fun, int orden)
{
    double t = 2.0;
    double o = alg(a, b, t * N, fun);
    double u = alg(a, b, N, fun);
    double intr = ((std::pow(t, orden) * o) - u)/(std::pow(t, orden) - 1);

    return intr;
}