#include <iostream>
#include <cmath>

bool isprime(int n);
int contar_primos(int m);


int main(int argc, char **argv) 
{
    int n = std::stoi(argv[1]);
    std::cout << contar_primos(n) << "\n";
    return 0;
}

int contar_primos(int m)
{
    int i = 0;
    int p = 1;
    for(int k = 2; p <= m ; k++)
    {
        if(isprime(k) == true){
            i = k;
            p = p + 1; 
        }
    }
    return i;
}

bool isprime(int n)
{
    bool flag = true;
    for(int a = 2; a*a <= n; a ++) 
    {
        if(n%a == 0){
            flag = false;
            break;
        }
    }
    return flag;
}