#include <iostream>
#include <string>
#include "primes.h"

int main(int arg, char **argv)
{
    int nmin{0}, nmax{0};  

    nmin = std::stoi(argv[1]);  
    nmax = std::stoi(argv[2]);


    int delta = 6; 
    for(int n = nmin; (n + delta + delta) <= nmax; n++){  
        if((isprime(n) == true) and (isprime(n + delta) == true) and (isprime(n + delta + delta))) {
            std::cout << "(" << n << ", " << n + delta << ", " << n + delta + delta << ")";
        }
    }
    std::cout << "\n";   

    return 0;
}
