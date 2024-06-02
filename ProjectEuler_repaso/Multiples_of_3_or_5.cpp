#include <iostream>

bool multiplos(int n);
int suma_multiplos(int m);

int main(int arg, char **argv)
{
    int n = std::stoi(argv[1]);

    std::cout << suma_multiplos(n) << "\n";

    return 0;
}

int suma_multiplos(int m)
{
    int suma = 0;
    for(int k = 1; k < m; k = k + 1){
        if(multiplos(k) == true){
            suma = suma + k;
        }
    }
    return suma;
}

bool multiplos(int n)
{
    bool i = false;
    if(n % 3 == 0 or n % 5 == 0){
        i = true;
    }

    return i;
}