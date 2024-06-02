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
void fill_matrix_vandermonde(std::vector<double> & matrix, const int M){

    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < M; jj++){
            matrix[ii*M + jj] = static_cast<int>(std::pow((ii + 2), jj));
        }
    }
    std::cout << "\n";
}

double trace_matrix(const std::vector<double> & matrix, int M, int N)
{
    double trace = 0.0;
    for(int ii = 0; ii < M; ii++){
        for(int jj = 0; jj < N; jj++){
            if(ii == jj){
                trace = trace + matrix[ii*N + jj];       
            }
        }
    }
    return trace;
}