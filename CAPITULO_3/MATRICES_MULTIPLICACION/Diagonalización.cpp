#include <iostream>
#include <vector>
#include <string>


int main(int argc, char** argv)
{
    int M = std::stoi(argv[1]);

    std::vector <double> matrix(M*M, 0.0);

    std::cout.precision(1);

    for(int ii = 0; ii < M; ii = ii + 1) {
        for(int jj = 0; jj < M; jj = jj + 1) {
            matrix[(ii * M) + jj] = (ii * M) + jj + 1;
        }
    }

    for(int ii= 0; ii < M; ii = ii + 1) {
        for(int jj = 0; jj < M; jj = jj + 1) {
            std::cout << matrix[(ii * M) + jj] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    for(int ii = 0; ii < M; ii = ii + 1) {
        for(int jj = 0; jj < M; jj = jj + 1) {
            if(ii == jj){
                double a = matrix[(ii * M) + jj];
                for(int kk = 0; kk < M; kk = kk + 1){
                    matrix[(ii * M) + kk] = (1.0/a) * matrix[(ii * M) + kk];
                }
                for(int ff = (ii + 1); ff < M; ff = ff + 1){
                    for(int cc = 0; cc < M; cc = cc + 1){
                        matrix[(ff * M) + cc] = matrix[(ff * M) + cc] - (matrix[(ff * M) + cc] * matrix[((ff - 1) * M) + cc]);
                    }
                }
            }
        }
    }

    for(int ii = 0; ii < M; ii = ii + 1) {
        for(int jj = 0; jj < M; jj = jj + 1) {
            std::cout << matrix[(ii * M) + jj] << "\t";
        }
        std::cout << "\n";
    }
}
