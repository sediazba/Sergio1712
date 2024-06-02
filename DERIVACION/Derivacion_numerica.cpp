#include <iostream>
#include <cmath>
#include <fstream>

double function(double x);
double deriv_forward(double x, double h);
double deriv_central(double x, double h);

int main(void)
{
    std::ofstream file("derivacion.txt");

    double x = 4.321;
    double valor_real = -10.2909;
    for(double k = 1; k <= 10; k++ ){
        double h = std::pow(10, -k);
        file << h << "  " << std::fabs((valor_real - deriv_forward(x, h))/valor_real) << "  " << std::fabs((valor_real - deriv_central(x, h))/valor_real) << "\n";
    }
    file.close();
    return 0;
}
double function(double x) 
{
    double f = 4*x*sin(x) + 7;

    return f;
}

double deriv_forward(double x, double h)
{
    double result1 = (function(x+h) - function(x))/h;
    return result1;
}

double deriv_central(double x, double h)
{
    double result2 = (function(x+(h/2)) - function(x-(h/2)))/h;
    return result2;
}
