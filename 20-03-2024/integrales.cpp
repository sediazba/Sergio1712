#include "integrales.h"

double trapezoid(double a, double b, int npoints, fptr fun)
{

    double suma = (fun(a) + fun(b))/2;
    double dx = (b - a)/npoints;

    for (int k = 1; k < npoints; ++k) {
        suma += fun(a + k*dx);
    }
    return suma*dx;
}

double simpson(double a, double b, int npoints, fptr fun) {
    double sum1 = 0;
    double sum2 = 0;
    double dx = (b - a) / npoints;

    for(int i = 1; i <= npoints; i = i + 2){
        double x = a + (i*dx);
        sum1 = sum1 + fun(x);
    }
    
     for(int i = 2; i < npoints; i = i + 2){
        double x = a + (i*dx);
        sum2 = sum2 + fun(x);
    }
    double simpson_result = ((dx/3)*(fun(a)+ (4*sum1) + (2*sum2) + fun(b)));
    return simpson_result;
}

double rich_intr(double a, double b, int n, fptr fun, algptr alg, int order) {

    double t = 2.0;
    double v1 = alg(a, b, n, fun);
    double v2 = alg(a, b, 2*n, fun);
    double aux = std::pow(t, order);
    return ((aux * v2) - v1) / (aux - 1.0);
}
