#include "matrix_utils.h"

int main(int argc, char** argv)
{
    const int seed = std::stoi(argv[1]);

    for(int ii = 2; ii < 11; ii = ii + 1){
        const int M = static_cast<int>(std::pow(2, ii));
        std::vector <double> A(M*M);
        std::vector <double> B(M*M);
        std::vector <double> C(M*M);

        fill_matrix_random(A, M, M, seed);
        fill_matrix_random(B, M, M, seed);

        auto start = std::chrono::high_resolution_clock::now();
        multipl_matrix(A, B, C, M, M);
        auto stop = std::chrono::high_resolution_clock::now();

        auto elapsed = std::chrono::duration<double>(stop - start);

        std::cout << M*M << "\t" << elapsed.count() << "\n";
    }
    return 0;
}