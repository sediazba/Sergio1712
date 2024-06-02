#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]); //numero de filas

    std::vector <double> matrix_vander(M*M);

    fill_matrix_vandermonde(matrix_vander, M);
    print_matrix(matrix_vander, M, M);

    std::cout << trace_matrix(matrix_vander, M, M) << "\n";

}