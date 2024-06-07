#include <iostream>
#include <cmath>
#include <vector>

using fptr = double(double);
double f(double x);
double gauss7(double a, double b, fptr fun);

int main(int argc, char** argv)
{
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);

    double valor_real = 2*std::sin(std::sqrt(8.7)) - 2*std::sqrt(8.7)*std::cos(std::sqrt(8.7)) - (2*std::sin(std::sqrt(2.0)) - 2*std::sqrt(2.0)*std::cos(std::sqrt(2.0)));

    std::cout.precision(16);
    std::cout << valor_real << "\t" << gauss7(a, b, f) << "\t" << std::fabs(1 - (gauss7(a, b, f)/valor_real)) << "\n";

    return 0;
}

double f(double x)
{
    double f = std::sin(std::sqrt(x));
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