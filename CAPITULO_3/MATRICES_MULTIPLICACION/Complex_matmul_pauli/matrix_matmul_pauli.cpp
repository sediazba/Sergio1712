#include "matrix_utils.h"

int main(int argc, char** argv)
{
    double A = std::stod(argv[1]);
    double eps = std::pow(10, A);
    commute_matrix_pauli(eps);
    return 0;
}