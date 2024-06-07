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

double gauss_5(double a, double b, fptr fun)
{
    std::vector <double> x(5);
    std::vector <double> w(5);

    //De acuerdo a la tabla, tenemos
    x[0] = -(1.0/3)*std::sqrt(5 + 2*std::sqrt(10.0/7));
    x[1] = -(1.0/3)*std::sqrt(5 - 2*std::sqrt(10.0/7));
    x[2] = 0.0;
    x[3] = (1.0/3)*std::sqrt(5 - 2*std::sqrt(10.0/7));;
    x[4] = (1.0/3)*std::sqrt(5 + 2*std::sqrt(10.0/7));;

    w[0] = (322.0 - 13*std::sqrt(70.0))/900;
    w[1] = (322.0 + 13*std::sqrt(70.0))/900;
    w[2] = 128.0/225;
    w[3] = (322.0 + 13*std::sqrt(70.0))/900;
    w[4] = (322.0 - 13*std::sqrt(70.0))/900;

    double result = 0.0;
    for(int ii = 0; ii < 5; ii = ii + 1){
        result = result + w[ii] * function(((b - a)* x[ii])/2 + ((b + a)/2));
    }
    return result*(b - a)/2 ;
}