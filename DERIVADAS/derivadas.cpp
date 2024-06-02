#include "derivadas.h"

double function(double x)
{
    double f = std::sin(x*x);
    return f;
}

double forward_deriv(double x, double h)
{
    double a = function(x+h);
    double b = function(x);

    double derivada = ((a - b)/h);

    return derivada;
}

double central_deriv(double x, double h)
{
    double a = function(x+h);
    double b = function(x-h);

    double derivada = ((a - b)/(2*h));

    return derivada;
}