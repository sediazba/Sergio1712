#include <iostream>
#include <vector>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    // Constructor
    Persona(std::string n, int e) {
        nombre = n;
        edad = e;
    }
};

int main() {
    Persona p1("Carlos", 25); // Llama al constructor
    std::cout << p1.nombre << " tiene " << p1.edad << " años." << std::endl;
    return 0;
}
