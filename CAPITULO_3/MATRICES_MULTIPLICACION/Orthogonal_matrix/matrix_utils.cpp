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
                matrix[ii*N + jj] = ii*N + jj;
        }
    }
}

void trans_matrix(const std::vector<double> & matrix, std::vector<double>& matrixt, int M, int N)
{
    for(int jj = 0; jj < N; jj = jj + 1){
        for(int ii = 0; ii < M; ii = ii + 1){
            matrixt[(jj*M) + ii] = matrix[(ii*N) + jj];
        }
    }
}

bool check_orthogonal_matrix(const std::vector<double> & A, int M, double eps)
{
    std::vector<double> trans_A(A.size());
    trans_matrix(A, trans_A, M, M);

    std::vector<double> resultado(A.size());
    multipl_matrix(A, trans_A, M, M, resultado);

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
            if ((std::fabs(resultado[ii*M + jj] - identidad[ii*M + jj])) >= eps){
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
