#include <iostream>
#include <cmath>

long long triplas_pitagoricas(void);

int main(void)
{
    std::cout << triplas_pitagoricas() << "\n";
}

long long triplas_pitagoricas(void)
{
    long long d = 0;
    for(long long  c = 1; c < 1000; c++){
        for(long long b = 1; b < c; b++){
            for(long long a = 1; a < b; a++)
                if((std::pow(std::abs(a), 2.0)) + (std::pow(b, 2.0)) == (std::pow(c, 2.0)) and a + b + c == 1000){
                        d = a * b * c;
                        break;
                }
            }
        }
    return d;
} 
