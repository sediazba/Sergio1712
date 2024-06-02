/*
1. Pedir el número
2. ¿Cuales son los numeros primos menores al número?
3. Sumar los numeros primos menores o iguales al numero
*/

#include <iostream>
#include <cmath>
#include <string>

bool isprime(long n);
long suma_primos_menores_que(long s);

int main(int argc, char **argv)
{
    long n = std::stoll(argv[1]);
    std::cout << suma_primos_menores_que(n) << "\n";
    
    return 0;
}

long suma_primos_menores_que(long s)
{
    long m = 0;   // Contador
    for(long k = 2; k <= s; k = k + 1){
        if(isprime(k) == true){
            m = m + k;  //Sumar si el número k es primo
        }
    }
    return m;
}

// Verficar si el número a sumar es primo o no

bool isprime(long n)
{
    bool prime = true;
    for(long a = 2; a <= std::sqrt(n); a = a + 1)
    {
        if(n % a == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}