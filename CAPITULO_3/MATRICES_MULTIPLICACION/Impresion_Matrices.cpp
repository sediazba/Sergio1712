#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    int M = std::stoi(argv[1]); //Filas
    int N = std::stoi(argv[2]);
    std::vector <double> array2d(M*N, 0.0);

    for(int ii= 0; ii < M; ii = ii + 1) {
        for(int jj = 0; jj < N; jj = jj + 1) {
            array2d[(ii * N) + jj] = (ii * N) + jj;
        }
    }
    for(int ii= 0; ii < M; ii = ii + 1) {
        for(int jj = 0; jj < N; jj = jj + 1) {
            std::cout << array2d[(ii * N) + jj] << "  ";
        }
        std::cout << "\n";
    }
}