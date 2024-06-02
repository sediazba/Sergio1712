#include "matrix_utils.h"
void print_matrix(const std::vector<double> & matrix, int M, int N){

    std::cout.setf(std::ios::scientific);
    std::cout.precision(3);

    for (int ii = 0; ii < M; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            std::cout << matrix[ii*N + jj] << "\t"; 
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void fill_matrix_random(std::vector<double> & matrix, const int M, const int N, const int seed){
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dis(0., 1.);

    std::generate(matrix.begin(), matrix.end(), [&gen, &dis](){return dis(gen); });
    /*for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < N; jj++){
            matrix[ii*N + jj] = dis(gen);
        }
    }*/
}

void multipl_matrix(const std::vector<double> & matrix, const std::vector<double> & matrixt, std::vector <double> & resultado, int M, int N)
{
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
}
