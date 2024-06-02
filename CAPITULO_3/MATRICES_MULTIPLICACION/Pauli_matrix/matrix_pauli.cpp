#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const double a1 = std::stod(argv[1]);
    const double a2 = std::stod(argv[2]);
    const double a3 = std::stod(argv[3]);

    std::vector<double> v(3);
    v[0] = a1;
    v[1] = a2;
    v[2] = a3;

    std::vector <std::complex<double>> matrix_pauli(4);    

    pauli(v, matrix_pauli);
    print_matrix(matrix_pauli, 2, 2);

    return 0;
}