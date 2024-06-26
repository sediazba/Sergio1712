#include "derivacion.h"

double forward_diff(double x, double h, fptr fun)
{
    return (fun(x+h) - fun(x))/h;
}

double central_diff(double x, double h, fptr fun)
{
    return (fun(x+h) - fun(x-h))/(2*h);
}

/*double rich_forward_diff(double x, double h, fptr fun)
{
    double t = 2;
    double v1 = forward_diff(x, h, fun);
    double v2 = forward_diff(x, h/t, fun);
    double aux = std::pow(t, 1.0);
    return (aux*v2 - v1)/(aux-1);
}

double rich_central_diff(double x, double h, fptr fun)
{
    double t = 2;
    double v1 = central_diff(x, h, fun);
    double v2 = central_diff(x, h/t, fun);
    double aux = std::pow(t, 2.0);
    return (aux*v2 - v1)/(aux-1);
}
*/
double rich_diff(double x, double h, fptr fun, algptr alg, int order) //alg representa la funcion forwar o central. Order el alfa de cada una
{
    double t = 2;
    double v1 = alg(x, h, fun);
    double v2 = alg(x, h/t, fun);
    double aux = std::pow(t, order);
    return (aux*v2 - v1)/(aux-1);  
}