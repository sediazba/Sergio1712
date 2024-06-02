#include <iostream>
#include <string>
#include <cmath>

long sum_digitos(long n);

int main(int argc, char **argv)
{
    long n = std::stoll(argv[1]);
    std::cout << sum_digitos(n) << "\n";

    return 0; 
}

long sum_digitos(long n)
{
    long a = 0;
    for(long k = 100; k <= 1; k = k / 10){
        int b = n/k; 
        n = n - k; 
        a = b; 
        a = a + k;
    }
    return a;
    }