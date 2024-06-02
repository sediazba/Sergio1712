#include <iostream>
#include <cmath>

int contar_numeros_primos(int m);
bool isprime(int a);

int main(void)
{
    int mmin = 2, mmax = 2000;

    for(int m = mmin; m < mmax; m = m + 1)
    {

    std::cout << m << "  " << contar_numeros_primos(m) << "\n"; 

    }
}

int contar_numeros_primos(int m)
{
    int i = 0; // contador
    for(int k = 2; k < m; k = k + 1){

        if(isprime(k) == true)
        {
            i = i + 1;
        }
    }
    return i;
}

bool isprime(int a)
{
    bool b = true; 
    for(int c = 2; c < a; c = c + 1)
    {
        if(a % c == 0)
        {
            b = false;
            break;
        }
    }
    return b;
}