#include "matrix_utils.h"
void print_matrix(const std::vector<double> & matrix, int M, int N){

    // std::cout.setf(std::ios::scientific);
    //std::cout.precision(2);

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
            matrix[ii*N + jj] = (ii*N) + jj + 1;
        }
    }
    std::cout << "\n";
}

void potencia_matrix(const std::vector<double> & matrix, int M, int p, std::vector<double> & B)
{
    std::vector <double> v(M*M);
    std::vector <double> identidad(M*M);

    if(p == 0){
        for(int ii = 0; ii < M; ii++){
            for(int jj = 0; jj < M; jj++){
                if(ii == jj){
                    identidad[(ii*M) + jj] = 1;
                }
            }
        }
        B = identidad;
    }else{
        B = matrix;
    }

    double sum = 0;
    int counter = 1;

    while(counter < p){
        for(int kk = 0; kk < M; kk = kk + 1) {
            for(int ii = 0; ii < M; ii = ii + 1) {
                for(int jj = 0; jj < M; jj = jj + 1) {
                    double m = B[(jj * M) + kk] * matrix[(ii * M) + jj];
                    sum = sum + m;
                }
                v[(ii*M) + kk] = sum;
                sum = 0;
            }
        }
        B = v;
        counter = counter + 1;
    }
}
