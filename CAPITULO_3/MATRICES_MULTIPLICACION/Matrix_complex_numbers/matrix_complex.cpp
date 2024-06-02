#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]);

    double epsilon = 10e-3;
    std::vector <std::complex<double>> matrix(M*M);   

    fill_matrix_complex(matrix, M, M);
    print_matrix(matrix, M, M);
    std::cout << check_hermitian_matrix(matrix, M, epsilon) << "\n";

    return 0;
}