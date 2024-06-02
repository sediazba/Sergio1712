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
            matrix[ii*N + jj] = (ii*N) + jj + 1;
        }
    }
    std::cout << "\n";
}

void polynomial(const std::vector<double> & matrix, const std::vector<double> & vector_coefficients, std::vector<double> & resultado, std::vector<double> & suma, int M){
    for(int p = 0; p < M; p = p + 1){
        potencia_matrix(matrix, M, p, resultado);
        multiplicacion_escalar(vector_coefficients[p], resultado, M);
        suma_matrix(suma, resultado, M);
    }
}

void multiplicacion_escalar(const int escalar, std::vector<double> & resultado, const int M){
    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < M; jj = jj + 1){
            resultado[(ii*M) + jj] = escalar * resultado[(ii*M) + jj];
        }
    }
}

void suma_matrix(std::vector<double> & suma, std::vector<double> & resultado, const int M){
    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < M; jj = jj + 1){
            suma[(ii*M) + jj] = suma[(ii*M) + jj] + resultado[(ii*M) + jj];
        }
    }    
}

void potencia_matrix(const std::vector<double> & matrix, int M, int p, std::vector<double> & B)
{
    std::vector <double> v(M*M);
    std::vector <double> identidad(M*M);
    
    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < M; jj = jj + 1){
            B[(ii*M) + jj] = 0;
        }
    }

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
