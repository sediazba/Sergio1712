#include <iostream>
#include <cmath>
#include <vector>

double f(double y, double t);
void euler(double y, double t0, double tf, double h);
void rk4(double y, double t0, double tf, double h);

int main(void)
{
    //Condiciones Inciales
    double y = 1.5;
    
    //euler(y, 0.0, 10.0, 0.1);

    //std::cout << "\n";

    rk4(y, 0.0, 10.0, 0.1);

    return 0;
}

double f(double y, double t)
{
    double dydt = (5*std::sin(t)) + t;
    return dydt;
}

void euler(double y, double t0, double tf, double h)
{
    for(double t = t0; t <= tf; t = t + h){
        std::cout << t << "\t" << y << "\t" << f(y, t) << "\n";
        double dydt = f(y, t);
        y = y + (h * dydt);
    }
}

void rk4(double y, double t0, double tf, double h)
{
    double aux, k1, k2, k3, k4;
    // avanzar desde y en t, hasta y en tf
    for(double t = t0; t <= tf; t = t + h) {
        // calcular derivadas
	    // k1
	    k1 = f(y, t); // guardo las derivadas en k1

	    // k2
	    aux = y + (0.5 * h * k1);
	    k2 = f(aux, t + 0.5*h); // guardo las derivadas en k2

	    // k3
	    aux = y + (0.5 * h * k2);
	    k3 = f(aux, t + 0.5*h); // guardo las derivadas en k3

	    // k4
	    aux = y + (h * k3);
	    k4 = f(aux, t + h); // guardo las derivadas en k4

        // aplicar rk4: mover en el tiempo
        y = y + h*(k1 + 2*k2 + 2*k3 + k4)/6.0;

        // imprimir
        double dydt = f(y, t);
        std::cout << t << "\t" << y << "\t" << dydt << "\n";
    }
}
