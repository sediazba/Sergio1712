#include <iostream>
#include <string>

bool isprime(long n);
long max_factor_primo(long m);

int main(int argc, char **argv)
{
    long n = std::stol(argv[1]);
    std::cout << max_factor_primo(n) << "\n";

    return 0;
}

long max_factor_primo(long m)
{
    long i = 0;
    for(int k = 2; k <= m; k = k + 1){

        while(m % k == 0){

            if(isprime(k) == true){
                i = k;
            }
            m = m/k;
        }
    }
    return i;
}


bool isprime(long n)
{
    bool a = true;
    for(int k = 2; k*k <= n; k = k + 1){
        if(n % k == 0){

            a = false;
            break;
        }
    }
    return a;
}