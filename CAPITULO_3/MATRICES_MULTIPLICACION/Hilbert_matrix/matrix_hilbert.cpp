#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]);
    const int N = std::stoi(argv[2]);

    std::vector <double> matrix(M*N);

    fill_matrix(matrix, M, N);
    print_matrix(matrix, M, N);

    std::cout << trace_matrix(matrix, M, N) << "\n";

}