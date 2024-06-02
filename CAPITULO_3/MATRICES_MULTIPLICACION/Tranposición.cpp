#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv)
{
    int M = std::stoi(argv[1]);
    int N = std::stoi(argv[2]);

    std::vector <double> matrix1(M*N, 0.0);
    std::vector <double> matrix_trans(N*M, 0.0);

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            matrix1[(ii*N) + jj] = 1.0/(ii + jj + 1);
        }
    }

    for(int jj = 0; jj < N; jj = jj + 1){
        for(int ii = 0; ii < M; ii = ii + 1){
            matrix_trans[(jj*M) + ii] = matrix1[(ii*N) + jj];
        }
    }

    std::cout.precision(6);
    std::cout.setf(std::ios::scientific);

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            std::cout << matrix1[(ii*N) + jj] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for(int jj = 0; jj < N; jj = jj + 1){
        for(int ii = 0; ii < M; ii = ii + 1){
            std::cout << matrix_trans[(jj*M) + ii] << "  ";
        }
        std::cout << "\n";
    }
}