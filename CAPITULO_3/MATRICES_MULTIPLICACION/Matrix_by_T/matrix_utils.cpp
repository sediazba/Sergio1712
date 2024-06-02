#include "matrix_utils.h"
void print_matrix(const std::vector<double> & matrix, int M, int N){

    // std::cout.setf(std::ios::scientific);
    std::cout.precision(2);

    for (int ii = 0; ii < M; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            std::cout << matrix[ii*N + jj] << "\t"; 
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void fill_matrix(std::vector<double> & matrix, const int M, const int N){
    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < N; jj++){
            matrix[ii*N + jj] = (ii*N) + jj;
        }
    }
    std::cout << "\n";
}

void trans_matrix(const std::vector<double> & matrix, std::vector<double>& matrixt, int M, int N)
{
    for(int jj = 0; jj < N; jj = jj + 1){
        for(int ii = 0; ii < M; ii = ii + 1){
            matrixt[(jj*M) + ii] = matrix[(ii*N) + jj];
        }
    }
}

void multipl_matrix(const std::vector<double> & matrix, const std::vector<double> & matrixt, int M, int N)
{
    std::vector <double> resultado(M*M);

    double sum = 0;

    for(int kk = 0; kk < M; kk = kk + 1) {
        for(int ii = 0; ii < M; ii = ii + 1) {
            for(int jj = 0; jj < N; jj = jj + 1) {
                double m = matrix[(ii * N) + jj] * matrixt[(jj * M) + kk];
                sum = sum + m;
            }
        resultado[(ii*M) + kk] = sum;
        sum = 0;
        }
    }

    for(int ii = 0; ii < M; ii = ii + 1) {
        for(int kk = 0; kk < M; kk = kk + 1) {
            std::cout << resultado[(ii * M) + kk] << "  ";
        }
        std::cout << "\n";
    }
}
