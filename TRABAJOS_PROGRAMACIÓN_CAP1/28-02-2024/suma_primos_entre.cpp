#include <iostream>
#include <string>

bool isprime(int m);

int main(int arg, char **argv)
{
    int nmin{0}, nmax{0};  //Lo vamos a ejecutar directo

    nmin = std::stoi(argv[1]);  //convierte una cadena en un entero stoi
    nmax = std::stoi(argv[2]);

//Barrer
    int suma = 0;
    for(int n = nmin; n <= nmax; n++){
        if(isprime(n)){
            suma = suma + n;
        }
    }
    std::cout << suma << "\n";   //al estar en main no retorna suma

    return 0;
}

bool isprime(int m)
{
    bool flag = true;
    for(int n = 2; n*n <= m; n++){   //para no usar la raiz cuadrada
        if (m % n == 0){
            flag = false;
            break;
        }
    }
    return flag;
}