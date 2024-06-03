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

double rich_forward_deriv(double x, double h)
{
    double t = 2.0;
    double orden = 1.0;
    double a = forward_deriv(x, h/t);
    double b = forward_deriv(x, h); 

    double deriv = (((std::pow(t, orden)* a) - b)/(std::pow(t, orden) - 1));

    return deriv;
}

double rich_central_deriv(double x, double h)
{
    double t = 2.0;
    int orden = 2;
    double a = central_deriv(x, h/t);
    double b = central_deriv(x, h); 

    double deriv = (((std::pow(t, orden)* a) - b)/(std::pow(t, orden) - 1));    

    return deriv;
}