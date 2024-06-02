#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]);
    const int p = std::stoi(argv[2]);
    double epsilon = 10e-12;
    std::vector <double> matrix(M*M);    

    fill_matrix(matrix, M, M);
    print_matrix(matrix, M, M);

    std::cout << check_idempotent_matrix(matrix, M, p, epsilon) << "\n";

    return 0;
}