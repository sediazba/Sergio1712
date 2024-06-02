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
void fill_matrix(std::vector<double> & matrix, const int M, const int N){
    for (int ii = 0; ii < M; ii++){
        for (int jj = 0; jj < N; jj++){
            matrix[ii*N + jj] = 1.0/(ii + jj + 1);
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