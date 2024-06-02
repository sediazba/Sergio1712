#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]);

    std::vector <double> matrix(M*M);  
    std::vector <double> coeficientes(M); 
    std::vector <double> resultado(M*M);
    std::vector <double> suma(M*M);

    for(int i = 0; i < M; i = i + 1){
        coeficientes[i] = i + 1;
    }

    fill_matrix(matrix, M, M);
    print_matrix(matrix, M, M);
    polynomial(matrix, coeficientes, resultado, suma, M);
    print_matrix(suma, M, M);
    
    return 0;
}