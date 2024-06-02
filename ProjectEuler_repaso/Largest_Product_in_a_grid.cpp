#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <random>

int main() {
    
    std::ifstream archivo("matrix.txt");

    std::vector<int> matrix;
    int num;

    while (archivo >> num) {
        matrix.push_back(num);
    }

    archivo.close(); // se guarda la matriz en un vector unidimensional

    int max_product = 0;
    //moviendose horizontalmente
    for(int ii = 0; ii < 20; ii = ii + 1){
        for(int jj = 0; jj < 17; jj = jj + 1){
            int n = matrix[(ii * 20) + jj] * matrix[(ii * 20) + (jj + 1)] * matrix[(ii * 20) + (jj + 2)] * matrix[(ii * 20) + (jj + 3)];
            if(n > max_product){
                max_product = n;
            }
        }
    }

    //moviendose verticalmente
    for(int jj = 0; jj < 20; jj = jj + 1){
        for(int ii = 0; ii < 17; ii = ii + 1){
            int n = matrix[(ii * 20) + jj] * matrix[((ii + 1) * 20) + jj] * matrix[((ii + 2) * 20) + jj] * matrix[((ii + 3) * 20) + jj];
            if(n > max_product){
                max_product = n;
            }
        }
    }

    // moviendose por diagonales de izq a der
    for(int ii = 0; ii < 17; ii = ii + 1){
        for(int jj = 0; jj < 17; jj = jj + 1){
            int n = matrix[(ii * 20) + jj] * matrix[((ii + 1) * 20) + (jj + 1)] * matrix[((ii + 2) * 20) + (jj + 2)] * matrix[((ii + 3) * 20) + (jj + 3)];
            if(n > max_product){
                max_product = n;
            }
        }
    }

    
    // moviendose por diagonales de der a izq
    for(int ii = 0; ii < 17; ii = ii + 1){
        for(int jj = 3; jj < 20; jj = jj + 1){
            int n = matrix[(ii * 20) + jj] * matrix[((ii + 1) * 20) + (jj - 1)] * matrix[((ii + 2) * 20) + (jj - 2)] * matrix[((ii + 3) * 20) + (jj - 3)];
            if(n > max_product){
                max_product = n;
            }
        }
    }

    std::cout << max_product << "\n";
    return 0;
}