#include <iostream>
#include <string>

bool isprime(int m);

int main(int arg, char **argv)
{
    int nmin{0}, nmax{0};  //Lo vamos a ejecutar directo

    nmin = std::stoi(argv[1]);  //convierte una cadena en un entero stoi
    nmax = std::stoi(argv[2]);

//Si n es prime y n + 4 también imrpimalos

//Barrer
    for(int n = nmin; n+2 <= nmax; n++){  //necesitamos que elsegundo valor no se pase
        if(isprime(n) == true and isprime(n+2) == true){
            std::cout << "(" << n << ", " << n+2 << ")";
        }
    }
    std::cout << "\n";   //al estar en main no retorna suma

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