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

void commute_matrix_pauli(double eps)
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

    std::cout << check_commute_matrix_complex(sigma1, sigma2, 2, eps) << "\n" << check_commute_matrix_complex(sigma1, sigma3, 2, eps) << "\n" << check_commute_matrix_complex(sigma2, sigma3, 2, eps) <<
            "\n" << check_commute_matrix_complex(sigma1, sigma1, 2, eps) << "\n" << check_commute_matrix_complex(sigma2, sigma2, 2, eps) << "\n" << check_commute_matrix_complex(sigma3, sigma3, 2, eps) << "\n";
}

bool check_commute_matrix_complex(const std::vector<std::complex<double>> & A, const std::vector<std::complex<double>> & B, int M, double eps)
{
    std::vector<std::complex<double>> resultado1(A.size());
    multipl_matrix_complex(A, B, M, M, resultado1);

    std::vector<std::complex<double>> resultado2(A.size());
    multipl_matrix_complex(B, A, M, M, resultado2);

    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < M; jj++){
            if ((std::fabs(resultado1[ii*M + jj] - resultado2[ii*M + jj])) >= eps){
                return false;
            } 
        }
    }
    return true;
}

void multipl_matrix_complex(const std::vector<std::complex<double>> & matrix, const std::vector<std::complex<double>> & matrixt, int M, int N, std::vector<std::complex<double>> & resultado)
{
    std::complex<double> sum;
    std::complex<double> m;

    for(int kk = 0; kk < M; kk = kk + 1) {
        for(int ii = 0; ii < M; ii = ii + 1) {
            for(int jj = 0; jj < N; jj = jj + 1) {
                m = matrix[(ii * N) + jj] * matrixt[(jj * M) + kk];
                sum = sum + m;
            }
        resultado[(ii*M) + kk] = sum;
        sum = 0;
        }
    }
}
