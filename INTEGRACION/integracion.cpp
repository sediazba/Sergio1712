#include "integracion.h"
double trapezoid(double a, double b, int npoints, fptr fun)
{
    double suma = (fun(a) + fun(b))/2; //inicializacion de suma, los extremos divididos en 2
    double dx = (b-a)/npoints;

    for (int ii = 1; ii < npoints; ++ii) {
        suma += fun(a + ii*dx);
    }

    return suma*dx;
}

double simpson(double a, double b, int npoints, fptr fun)
{
    double suma = (fun(a) + fun(b));
    double dx = (b-a)/npoints;

    for (int ii = 1; ii <= npoints; ii = ii + 2)
    {
        suma += 4.0*(fun(a + dx*ii)); 
    }

    for (int ii = 2; ii <= (npoints - 1.0); ii = ii + 2)
    {
        suma += 2.0*(fun(a + dx*ii));
    }

    return suma*dx/3.0;
}

double rich_inte(double a, double b, int npoints, fptr fun, algptr alg, int order)
{
    double t = 4.0;
    double v1 = alg(a, b, npoints/2.0, fun);
    double v2 = alg(a, b, npoints, fun);
    double aux = std::pow(t, order);
    return (aux*v2 - v1)/(aux-1.0);
}

// double rich_inte(double a, double b, int npoints, fptr fun, algptr alg, int order)
// {
//     double t = 4.0;
//     double v1 = alg(a, b, npoints/2.0, fun);
//     double v2 = alg(a, b, npoints, fun);
//     double aux = std::pow(t, order-1.0);
//     return (aux*v2 - v1)/(aux-1.0);
// }