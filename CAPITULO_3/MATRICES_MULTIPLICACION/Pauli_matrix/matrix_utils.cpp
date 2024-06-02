#include "matrix_utils.h"
void print_matrix(const std::vector<std::complex<double>> & matrix, int M, int N){
    for (int ii = 0; ii < M; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            std::cout << matrix[ii*N + jj] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void pauli(const std::vector<double> & v, std::vector<std::complex<double>> & matrix_pauli)
{

    std::vector<std::complex<double>> sigma1(4);
    sigma1[0] = std::complex<double>(0, 0);
    sigma1[1] = std::complex<double>(1, 0);
    sigma1[2] = std::complex<double>(1, 0);
    sigma1[3] = std::complex<double>(0, 0);

    std::vector<std::complex<double>> sigma2(4);
    sigma2[0] = std::complex<double>(0, 0);
    sigma2[1] = std::complex<double>(0, -1);
    sigma2[2] = std::complex<double>(0, 1);
    sigma2[3] = std::complex<double>(0, 0);  

    std::vector<std::complex<double>> sigma3(4);
    sigma3[0] = std::complex<double>(1, 0);
    sigma3[1] = std::complex<double>(0, 0);
    sigma3[2] = std::complex<double>(0, 0);
    sigma3[3] = std::complex<double>(-1, 0);   

    std::vector<std::complex<double>> m1(4);
    std::vector<std::complex<double>> m2(4);
    std::vector<std::complex<double>> m3(4);

    for(int ii = 0; ii < 2; ii = ii + 1){
        for(int jj = 0; jj < 2; jj = jj + 1){
            m1[ii*2 + jj] = v[0] * sigma1[ii*2 + jj];
            m2[ii*2 + jj] = v[1] * sigma2[ii*2 + jj];
            m3[ii*2 + jj] = v[2] * sigma3[ii*2 + jj];
        }
    }


    std::vector<std::complex<double>> resultado(4);
    suma_matrix(m1, m2, resultado);

    suma_matrix(resultado, m3, matrix_pauli);
}

void suma_matrix(const std::vector<std::complex<double>> & m1, const std::vector<std::complex<double>> & m2, std::vector<std::complex<double>> & resultado)
{
    for(int ii = 0; ii < 2; ii = ii + 1){
        for(int jj = 0; jj < 2; jj = jj + 1){
            resultado[(ii*2) + jj] = m1[(ii*2) + jj] + m2[(ii*2) + jj];
        }
    }
}