#include "matrix_utils.h"
void print_matrix(const std::vector<double> & matrix, int M, int N){
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
            if(ii == jj){
                matrix[ii*N + jj] = 1;
            }
        }
    }
}

bool check_inverse_matrix(const std::vector<double> & A, const std::vector<double> & B, int M, double eps)
{
    std::vector<double> resultado1(A.size());
    multipl_matrix(A, B, M, M, resultado1);

    std::vector<double> resultado2(A.size());
    multipl_matrix(B, A, M, M, resultado2);

    std::vector<double> identidad(M*M);
    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < M; jj++){
            if(ii == jj){
                identidad[(ii*M) + jj] = 1;
            }
        }
    }

    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < M; jj++){
            if ((std::fabs(resultado1[ii*M + jj] - identidad[ii*M + jj]) or (std::fabs(resultado2[ii*M + jj] - identidad[ii*M + jj]))) >= eps){
                return false;
            } 
        }
    }
    return true;
}

void multipl_matrix(const std::vector<double> & matrix1, const std::vector<double> & matrix2, int M, int N, std::vector<double> & resultado)
{
    double sum = 0;

    for(int kk = 0; kk < M; kk = kk + 1) {
        for(int ii = 0; ii < M; ii = ii + 1) {
            for(int jj = 0; jj < N; jj = jj + 1) {
                double m = matrix1[(ii * N) + jj] * matrix2[(jj * M) + kk];
                sum = sum + m;
            }
        resultado[(ii*M) + kk] = sum;
        sum = 0;
        }
    }
}
