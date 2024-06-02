#include <iostream>
#include <cmath>

bool isprime(int m);
void nth_twin_primes(int n);

int main(int argc, char **argv) {
    int n = std::stoi(argv[1]);  // Convertir el argumento de línea de comandos a un entero
    
    nth_twin_primes(n);
    return 0;
}

bool isprime(int m) {
    if (m <= 1)
        return false;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0)
            return false;
    }
    return true;
}

void nth_twin_primes(int n) { 
    int a = 0;
    for(double k = 2; a < n; k++){
        if (isprime(k) == true and isprime(k + 2) == true) {
            a = a + 1;
            std::cout << a << "  " << std::sqrt((std::pow(k, 2)) + (std::pow(k + 2, 2))) << "\n";
        }
    }
    }
