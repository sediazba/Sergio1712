#include <iostream>
#include <vector>
#include <string>

class Persona {
public:
    std::string nombre;

    // Constructor
    Persona(std::string n) : nombre(n) {
        std::cout << "Constructor llamado para " << nombre << std::endl;
    }

    // Destructor
    ~Persona() {
        std::cout << "Destructor llamado para " << nombre << std::endl;
    }
};

int main() {
    Persona p1("Carlos"); // Llama al constructor
    // Al finalizar main, se llama al destructor de p1 automáticamente
    return 0;
}
