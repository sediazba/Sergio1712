#include <iostream>
#include <vector>

void Multiplicacion_Matrices(std::vector <double>, std::vector <double>);

int main(int argc, char** argv)
{
    int M = std::stoi(argv[1]); //Filas
    int N = std::stoi(argv[2]); //Columnas1, Filas2
    int C = std::stoi(argv[3]); //Columnas2
    std::vector <double> matrix1(M*N, 0.0);
    std::vector <double> matrix2(N*C, 0.0);
    std::vector <double> mult(M*C, 0.0);

    for(int ii= 0; ii < M; ii = ii + 1) {
        for(int jj = 0; jj < N; jj = jj + 1) {
            matrix1[(ii * N) + jj] = (ii * N) + jj;
        }
    }
    for(int ii= 0; ii < N; ii = ii + 1) {
        for(int jj = 0; jj < C; jj = jj + 1) {
            matrix2[(ii * C) + jj] = (ii * C) + jj;
        }
    }

    double sum = 0;

    for(int kk = 0; kk < C; kk = kk + 1) {
        for(int ii = 0; ii < M; ii = ii + 1) {
            for(int jj = 0; jj < N; jj = jj + 1) {
                double m = matrix1[(ii * N) + jj] * matrix2[(jj * C) + kk];
                sum = sum + m;
            }
        mult[(ii*C) + kk] = sum;
        sum = 0;
        }
    }
    for(int ii= 0; ii < M; ii = ii + 1) {
        for(int kk = 0; kk < C; kk = kk + 1) {
            std::cout << mult[(ii * C) + kk] << "  ";
        }
        std::cout << "\n";
    }
}
