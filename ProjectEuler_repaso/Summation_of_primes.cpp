#include <iostream>
#include <cmath>

long suma_primos_menores_que(long n);
bool isprime(long m);

int main(int argc, char **argv)
{
    long n = std::stoi(argv[1]);
    std::cout << suma_primos_menores_que(n) << "\n";
    return 0;
}

long suma_primos_menores_que(long n)
{
    long a = 0;
    for(long k = 2; k < n; k++)
    {
        if(isprime(k) == true){
            a = a + k;
        }

    }
    return a;
}

bool isprime(long m)
{
    bool flag = true;
    for(long i = 2; i <= std::sqrt(m); i++){
        if(m % i == 0){
            flag = false;
            break;
        }
    }
    return flag;
}
