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

void fill_matrix_complex(std::vector<std::complex<double>> & matrix, const int M, const int N){

    matrix[0] = (0, 0);
    matrix[1] = (0, -1);
    matrix[2] = (0, 1);
    matrix[3] = (0, 0);
    /*int seed = 0;
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> uniform_dis(1.0, 10.0);

    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < N; jj++){
            double real_part = uniform_dis(gen);
            double imag_part = uniform_dis(gen);
            matrix[ii*N + jj] = std::complex<double> (real_part, imag_part);
        }
    }*/
}

void trans_matrix_complex(const std::vector<std::complex<double>> & matrix, std::vector<std::complex<double>>& matrixt, int M, int N)
{
    for(int jj = 0; jj < N; jj = jj + 1){
        for(int ii = 0; ii < M; ii = ii + 1){
            matrixt[(jj*M) + ii] = matrix[(ii*N) + jj];
        }
    }
}

bool check_hermitian_matrix(const std::vector<std::complex<double>> & matrix, int M, double eps)
{
    std::vector<std::complex<double>> matrixt(matrix.size());
    trans_matrix_complex(matrix, matrixt, M, M);

    std::vector<std::complex<double>> conjugado(matrix.size());
    conjugado_matrix_complex(matrix, conjugado, M);

    std::vector<std::complex<double>> resultado(matrix.size());
    multipl_matrix(conjugado, matrixt, M, M, resultado);

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

void conjugado_matrix_complex(const std::vector<std::complex<double>> & matrix, std::vector<std::complex<double>> & conjugado, int M)
{
    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < M; jj++){
            conjugado[ii*M + jj] = std::conj(matrix[ii*M + jj]);
        }
    }    
}

void multipl_matrix(const std::vector<std::complex<double>> & matrix1, const std::vector<std::complex<double>> & matrix2, int M, int N, std::vector<std::complex<double>> & resultado)
{
    std::complex<double> m;
    std::complex<double> sum;

    for(int kk = 0; kk < M; kk = kk + 1) {
        for(int ii = 0; ii < M; ii = ii + 1) {
            for(int jj = 0; jj < N; jj = jj + 1) {
                m = matrix1[(ii * N) + jj] * matrix2[(jj * M) + kk];
                sum = sum + m;
            }
        resultado[(ii*M) + kk] = sum;
        sum = 0;
        }
    }
}
