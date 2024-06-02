#include <iostream>

long long Fibonacci(long long n);
long long suma_pares(long long m);


int main(int arg, char **argv)
{
    long long n = std::stoll(argv[1]);

    std::cout << Fibonacci(n) << "  " << suma_pares(n) << "\n";

    return 0;
}

long long suma_pares(long long m)
{
    long long suma = 0;
    for(long long k = 1; Fibonacci(k) < m; k = k + 1){
        if(Fibonacci(k) % 2 == 0){
            suma = suma + Fibonacci(k);
        }
    }

    return suma;
}

long long Fibonacci(long long n)
{
    int a = 0, b = 1, resultado = 0;
    for(long i = 1; i <= n; i = i + 1){
        resultado = a + b;
        a = b;
        b = resultado;
    }
    return resultado;
}