#include <iostream>
#include <string>
#include "primes.h"

int main(int argc, char **argv)
{
    // ./a.out nmin nmax
    int nmin{0}, nmax{0};
    // leer los limites desde la linea de comando
    nmin = std::stoi(argv[1]);
    nmax = std::stoi(argv[2]);

    // kernel: if n is primer AND n+4 is prime
    for(int n = nmin; n+4 <= nmax; n++) {
        if (isprime(n) == true and isprime(n+4) == true) {
            std::cout << "(" << n << ", " << n+4 << ") ";    
        }
    }
    std::cout << "\n";

    return 0;
}

