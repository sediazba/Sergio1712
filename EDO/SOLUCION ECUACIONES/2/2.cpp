#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

double f(double y, double t);
void euler(double y, double t0, double tf, double h);
void rk4(double y, double t0, double tf, double h);

int main(void)
{
    //Condiciones Inciales
    double y = 2.0;
    
    euler(y, 0.0, 20.0, 0.1);
    rk4(y, 0.0, 20.0, 0.1);

    return 0;
}

double f(double y, double t)
{
    double dydt = ((-5*t)-(4*y))/((4*t)-(8*std::pow(y, 3)));
    return dydt;
}

void euler(double y, double t0, double tf, double h)
{
    std::ofstream fout("datoseuler.txt");
    for(double t = t0; t <= tf; t = t + h){
        fout << t << "\t" << y << "\t" << f(y, t) << "\n";
        double dydt = f(y, t);
        y = y + (h * dydt);
    }
    fout.close();
}

void rk4(double y, double t0, double tf, double h)
{
    double aux, k1, k2, k3, k4;
    // avanzar desde y en t, hasta y en tf
    std::ofstream fout("datosrk4.txt");
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
        fout << t << "\t" << y << "\t" << dydt << "\n";
    }

    fout.close();
}

