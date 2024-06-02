#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]);
    const int p = std::stoi(argv[2]);

    std::vector <double> matrix(M*M);  
    std::vector <double> B(M*M); 

    fill_matrix(matrix, M, M);
    print_matrix(matrix, M, M);
    potencia_matrix(matrix, M, p, B);

    
    for(int ii = 0; ii < M; ii = ii + 1) {
        for(int kk = 0; kk < M; kk = kk + 1) {
            std::cout << B[(ii * M) + kk] << "\t";
        }
        std::cout << "\n";
    }
    return 0;
}