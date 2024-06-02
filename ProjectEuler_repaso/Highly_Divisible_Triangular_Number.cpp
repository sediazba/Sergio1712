#include <iostream>
#include <cmath>

long long numeros_triangulares(void);
long long count_divisors(long long m);

int main(void)
{
    std::cout << numeros_triangulares() << "\n";
    return 0;
}

long long numeros_triangulares(void)
{
    long long i = 0;
    for(long long k = 1; ; k ++){
        i = i + k;
        if(count_divisors(i) > 500){
            break;
        }
    }
    return i;
}

long long count_divisors(long long m)
{
    long long a = 0;
    for(long long ii = 1; ii <= std::sqrt(m); ii ++){
        if(m % ii == 0){
            a = a + 1;
        }
    }
    return 2*a;
}