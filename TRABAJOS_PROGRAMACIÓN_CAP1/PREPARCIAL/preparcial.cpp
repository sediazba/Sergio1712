#include <iostream>

bool isprime(int m);
void nth_twin_primes(int n);


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
    int b = 2;

    while (a < n) {
        if (isprime(b) == true and isprime(b + 2) == true) {
            if (a == n - 1) {
                std::cout << "(" << b << ", " << b + 2 << ")" << "\n";
                return;
            }
            a = a + 1;
        }
        b = b + 1;
    }
}
