#include <iostream>
#include <iomanip>  // Incluir esta librería

int main() {
    double valor = 3.14159265359;
    
    // Cambiar la precisión a 4 decimales
    std::cout << std::fixed << std::setprecision(4) << valor << std::endl;
    
    return 0;
}
