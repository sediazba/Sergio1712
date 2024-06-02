#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <numero>" << std::endl;
        return 1;
    }

    std::string numero_str = argv[1];
    
    std::cout << "Digitos del numero " << numero_str << ":" << std::endl;
    for (char digito : numero_str) {
        std::cout << digito << std::endl;
    }

    return 0;
}
