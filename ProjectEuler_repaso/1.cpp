#include <iostream>
#include <string>
using namespace std;

// Función para sumar los dígitos de una cadena
int sumaDigitos(string numero) {
    int suma = 0;
    for (char digito : numero) {
        suma += digito - '0'; // Convertir el carácter a entero
    }
    return suma;
}

int main() {
    // Calcula 2 elevado a la 1000 como una cadena
    string resultado = "1"; // Inicializamos con 2^0 = 1
    for (int i = 0; i < 1000; ++i) {
        int carry = 0;
        for (char& digito : resultado) {
            int producto = (digito - '0') * 2 + carry;
            digito = '0' + producto % 10;
            carry = producto / 10;
        }
        if (carry > 0) {
            resultado.push_back('0' + carry);
        }
    }

    // Suma los dígitos del resultado
    int suma = sumaDigitos(resultado);

    cout << "La suma de los dígitos de 2^1000 es: " << suma << endl;

    return 0;
}