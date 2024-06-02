#include <iostream>
#include <vector>
#include <string>

int main(int argc, char** argv)
{
    int M = std::stoi(argv[1]);
    int N = std::stoi(argv[2]);

    std::vector <double> matrix1(M*N, 0.0);
    std::vector <double> matrix2(M*N, 0.0);
    std::vector <double> matrix_sum(M*N, 0.0);

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            matrix1[(ii*N) + jj] = 1;
        }
    }

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            matrix2[(ii*N) + jj] = ((ii*N) + jj);
        }
    }

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            matrix_sum[(ii*N) + jj] = matrix1[(ii*N) + jj] + matrix2[(ii*N) + jj];
        }
    }

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            std::cout << matrix1[(ii*N) + jj] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            std::cout << matrix2[(ii*N) + jj] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for(int ii = 0; ii < M; ii = ii + 1){
        for(int jj = 0; jj < N; jj = jj + 1){
            std::cout << matrix_sum[(ii*N) + jj] << "\t";
        }
        std::cout << "\n";
    }
    return 0;
}