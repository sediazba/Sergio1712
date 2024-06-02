#include <iostream>
#include <string>

int main(void)
{
    std::cout << "Escribe tu nombre: \n";

    std::string nombre;
    std::getline(std::cin, nombre); // permite impimir con espacios

    // std::cin se encarga de leer lo escrito en la entrada estandar y asignarlo a una variable
    
    std::cout << "Hola " << nombre << "\n";

    return 0;

}