#include <iostream>
#include <cmath>

int count_primes_less_than(int m);
bool isprime(int a);

int main(void)
{
    int mmin = 2, mmax = 2000;

    for(int m = mmin; m < mmax; m=m+1) //variacion
    {
        
        std::cout << m << "\t" << count_primes_less_than(m) << "\n";   
    }
}

int count_primes_less_than(int m)
{
    int i = 0; //contador
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
    bool b = true;   //verificar si es primo
    for(int c = 2; c <= std::sqrt(a); c = c+1)
    {
        if(a % c == 0)
        {
            b = false;
            break;
        }
    }
    return b;
}