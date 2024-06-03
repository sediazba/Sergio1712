#include "derivadas.h"

double function(double x)
{
    double f = std::sin(x*x);
    return f;
}

double forward_deriv(double x, double h, fptr fun)
{
    double a = fun(x+h);
    double b = fun(x);

    double derivada = ((a - b)/h);

    return derivada;
}

double central_deriv(double x, double h, fptr fun)
{
    double a = fun(x+h);
    double b = fun(x-h);

    double derivada = ((a - b)/(2*h));

    return derivada;
}

double richardson_deriv(double x, double h, algptr alg, int orden)
{
    double t = 2.0;
    double a = alg(x, h/t, function);
    double b = alg(x, h, function); 

    double deriv = (((std::pow(t, orden)* a) - b)/(std::pow(t, orden) - 1));

    return deriv;
}
