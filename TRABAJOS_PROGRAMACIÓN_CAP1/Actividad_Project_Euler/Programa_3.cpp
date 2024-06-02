/*
1. Dar un valor límite n
2. Insertar la secuencia Fibonacci
3. Hacer un loop que verifique si los numeros de la misma son impares y luego los suma en caso afirmativo, hasta n
4. Imprimir la suma de esos números impares

*/

#include <iostream>
#include <string>

int Fibonacci(int s);
int suma_impares_Fibonacci(int n);

int main(int argc, char **argv)
{
    int n = std::stoll(argv[1]);
    std::cout << suma_impares_Fibonacci(n) << "\n";

    return 0;
}

int Fibonacci(int s)
{  // A continuacion se muestran las variables a manejar para exponer la suma de la secuencia Fibonacci
    int a = 0;
    int b = 1;
    int resultado = 0;
    for(int k = 0; k < s; k = k + 1){
        resultado = a + b;   //Bucle de suma
        a = b;
        b = resultado;
    }

    return resultado;
}

int suma_impares_Fibonacci(int n)
{
    int i = 0;
    for(int k = 0; Fibonacci(k) <= n; k = k + 1){ //Bucle de la funcion Fibonacci hasta valores iguales al n insertado
        if(Fibonacci(k) % 2 != 0){
            i = i + Fibonacci (k);   //Suma de impares menores al valor n dado
        }
    }

    return i;
}