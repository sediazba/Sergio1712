#include <iostream>
#include <cmath>
#include <vector>

using fptr = double(double);
using algptr = double(double, double, double, fptr);
double f(double x);
double gauss7(double a, double b, fptr fun);
double simpson(double a, double b, double N, fptr fun);
double richardson(double a, double b, double N, algptr alg, fptr fun, int orden);


int main(int argc, char** argv)
{
    double a = 0.0;

    for(double b = 0.5; b <= 10; b = b + 0.5){
        double N = (b-a)/0.05;
        double valor_real = std::erf(b);

        std::cout.precision(16);

        std::cout << b << "\t" << std::fabs(1 - (gauss7(a, b, f)/valor_real)) << "\t" << std::fabs(1 - (richardson(a, b, N, simpson, f, 4)/valor_real)) << "\n";
        //std::cout << valor_real << "\t" << gauss7(a, b, f) << "\t" << richardson(a, b, N, simpson, f, 4) << "\t" << std::fabs(1 - (gauss7(a, b, f)/valor_real)) << "\t" << std::fabs(1 - (richardson(a, b, N, simpson, f, 4)/valor_real))<< "\n";
    }
    return 0;
}

double f(double x)
{
    double f = std::pow(M_E, -x*x);
    return f;
}

double gauss7(double a, double b, fptr fun)
{
    std::vector <double> x(7);
    std::vector <double> w(7);

    x[0] = -0.949107912342759;
    x[1] = -0.741531185599394;
    x[2] = -0.405845151377397;
    x[3] = 0.0;
    x[4] = 0.405845151377397;
    x[5] = 0.741531185599394;
    x[6] = 0.949107912342759;

    w[0] = 0.129484966168870;
    w[1] = 0.279705391489277;
    w[2] = 0.381830050505119;
    w[3] = 0.417959183673469;
    w[4] = 0.381830050505119;
    w[5] = 0.279705391489277;
    w[6] = 0.129484966168870;

    double result = 0.0;
    for(int ii = 0; ii < 7; ii = ii + 1){
        result = result + w[ii]*f(((b-a)*x[ii]/2) + (b+a)/2);
    }

    return result*(b-a)/2;
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