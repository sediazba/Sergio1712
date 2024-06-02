//Este programa fue hecho por Sergio Andres Diaz Barajas

#include <iostream>
#include <cmath>

double pi_aprox(int n);

int main(void)
{
    int nmin = 1, nmax = 20;     //Definimos las variables a utilizar

    //Expresamos las respuestas en notacion cientifica y la cantidad de cifras significativas a usar

    std::cout.precision(16);             
    std::cout.setf(std::ios::scientific);      

    //Definimos el ciclo e imprimimos las aproximaciones dadas de la función

    for(int n = nmin; n <= nmax; n = n + 1 ){
        std::cout << n << "   "  << pi_aprox(n) << "   "  << fabs(1 - pi_aprox(n)/M_PI) << "\n";
    }
    // fabs(x) es el valor absoluto para double
    return 0;
}

double pi_aprox(int n)
{
    double resultado = 0.0;      //Definimos el resultado que va a arrojar la función

//Establacemos el ciclo de la variable k y devolvemos la variable "resultado"

    for(double k = 0.0; k <= n; k = k+1){

        resultado = resultado + ((1/pow(16, k))*((4/(8*k + 1))-(2/(8*k + 4))-(1/(8*k + 5))-(1/(8*k + 6))));
        }
    return resultado;
}