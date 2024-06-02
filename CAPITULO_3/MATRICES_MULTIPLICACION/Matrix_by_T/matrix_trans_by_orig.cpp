#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]);
    const int N = std::stoi(argv[2]);

    std::vector <double> matrix(M*N);
    std::vector <double> matrixt(N*M);    

    fill_matrix(matrix, M, N);
    print_matrix(matrix, M, N);
    trans_matrix(matrix, matrixt, M, N);
    print_matrix(matrixt, N, M);
    multipl_matrix(matrix, matrixt, M, N);

    return 0;
}