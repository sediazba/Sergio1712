/*
1. Verificar si el valor insertado es primo
2. Hallar factores primos if else
3. Imprimir el más grande
*/

#include <iostream>
#include <cmath>
#include <string>

bool isprime(long n);
long hallar_max_factor_primo_de(long s);

int main(int argc, char **argv)
{
    long n = std::stoll(argv[1]);
    std::cout << hallar_max_factor_primo_de(n) << "\n";

    return 0;
}

long hallar_max_factor_primo_de(long s)
{
    long i = 0;   //Contador
    for(int k = 2; k <= s; k = k + 1) //Bucle sobre k que hará las veces de factores primos
    {
        while (s % k == 0){    //Mientras el residuo entre el número dado y un factor primo sea 0

            if(isprime(k) == true){
                i = k;  //Asignar a i el valor del factor primo en el que vamos en el ciclo
                }

            s = s/k; //Operación de division para ir llegando al máximo factor primo
        }
    }
    return i;
    }

//Funcion para saber si k es primo o no

bool isprime(long n)
{
    bool prime = true;
    for(int a = 2; a <= std::sqrt(n); a = a + 1)
    {
        if(n % a == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}