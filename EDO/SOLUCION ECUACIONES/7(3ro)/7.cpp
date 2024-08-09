#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <vector>

void f(std::vector <double> & s, std::vector <double> & dsdt, double t);
void euler(std::vector <double> & s, double t0, double tf, double h);
void rk4(std::vector <double> & s, double t0, double tf, double h);

int main(void)
{
    //Condiciones Inciales
    std::vector <double> s(3);
    s[0] = -4.0; // y
    s[1] = 4.0; // dydt
    s[2] = -2.0; // dy2/dt2
    euler(s, 0.0, 50.0, 0.1); // al t iniciar en 0 y calcular las componentes de la derivada el valor no existe y se detien, por ello pongo un valor cerca a 0

    s[0] = -4.0; // y
    s[1] = 4.0; // dydt
    s[2] = -2.0; // dy2/dt2
    rk4(s, 0.0, 50.0, 0.1);

    return 0;
}

void f(std::vector <double> & s, std::vector <double> & dsdt, double t)
{  //ecuaciones que correspondan a la ecuación diferencial
    dsdt[0] = s[1];
    dsdt[1] = s[2];
    dsdt[2] = - s[0] - 3*s[1] - 3*s[2];
}

void euler(std::vector <double> & s, double t0, double tf, double h)
{
    std::vector <double> dsdt(s.size());
    std::ofstream fout("datoseuler.txt");
    for(double t = t0; t <= tf; t = t + h){
        f(s, dsdt, t);
        fout << t << "\t" << s[0] << "\t" << s[1] << dsdt[0] << "\t" << dsdt[1] << "\n";
        for(int ii = 0; ii < s.size(); ii = ii + 1){
            s[ii] = s[ii] + (h * dsdt[ii]);
        }
    }
    fout.close();
}

void rk4(std::vector <double> & s, double t0, double tf, double h)
{
    std::vector <double> dsdt(s.size());
    std::vector <double> aux(s.size()), k1(s.size()), k2(s.size()), k3(s.size()), k4(s.size());
    // avanzar desde y en t, hasta y en tf
    std::ofstream fout("datosrk4.txt");
    for(double t = t0; t <= tf; t = t + h) {
        // calcular derivadas
	    // k1
	    f(s, k1, t); // guardo las derivadas en k1

	    // k2
        for(int ii = 0; ii < s.size(); ii = ii + 1){
	        aux[ii] = s[ii] + (0.5 * h * k1[ii]);
        }
	    f(aux, k2, t + 0.5*h); // guardo las derivadas en k2

	    // k3
        for(int ii = 0; ii < s.size(); ii = ii + 1){
	        aux[ii] = s[ii] + (0.5 * h * k2[ii]);
        }
	    f(aux, k3, t + 0.5*h); // guardo las derivadas en k3

	    // k4
        for(int ii = 0; ii < s.size(); ii = ii + 1){
	        aux[ii] = s[ii] + (h * k3[ii]);
        }
	    f(aux, k4, t + h); // guardo las derivadas en k4

        // aplicar rk4: mover en el tiempo
        for(int ii = 0; ii < s.size(); ii = ii + 1){
            s[ii] = s[ii] + h*(k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
        }

        // imprimir
        fout << t << "\t" << s[0] << "\t" << s[1] << "\t" << s[2] << "\t" << k1[0] << "\t" << k1[1] << "\t" << k1[2] << "\n";
    }

    fout.close();
}

