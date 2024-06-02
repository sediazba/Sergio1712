/*
    Velásquez Sarmiento Estefanía
    Llanes Fernández Jeysson
    Ballesteros Martinez Manuel
    Cruz Ospina Fredy Estaban
    Diaz Barajas Sergio Andres
*/
#include <iostream>
#include <cmath>

bool isPrime(int a);

int main(void){
    int n = 0;
    std::cout << "n \n";
    std::cin >> n;

    if (n <= 10)
    {
        if(isPrime(n))
        {
            std::cout << "The number is prime \n"; 
        }
        else
        {
           std::cout << "The number is not prime \n";  
        }
    }
    else
    {
        std::cout << "Too large to verify manually \n"; 
    }
return 0;
}

bool isPrime(int a)
{
    bool b = true;
    for (int c = 2; c <= std::sqrt(a); c = c + 1)
    {
        if (a % c == 0)
        {
            b = false;
            break;
        }
    }
    return b;
}