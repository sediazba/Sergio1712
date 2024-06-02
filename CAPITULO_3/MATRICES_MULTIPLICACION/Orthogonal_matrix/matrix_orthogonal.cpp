#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int M = std::stoi(argv[1]);

    double epsilon = 10e-3;
    std::vector <double> matrix1(M*M);    

    fill_matrix(matrix1, M, M);
    print_matrix(matrix1, M, M);
    
    std::cout << check_orthogonal_matrix(matrix1, M, epsilon) << "\n";

    return 0;
}