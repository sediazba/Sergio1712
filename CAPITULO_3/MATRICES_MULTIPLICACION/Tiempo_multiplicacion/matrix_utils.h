#pragma once
#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
void print_matrix(const std::vector<double> & matrix, int M, int N);
void fill_matrix_random(std::vector<double> & matrix, const int M, const int N, const int seed);
void multipl_matrix(const std::vector<double> & matrix1, const std::vector<double> & matrix2, std::vector<double> & resultado, int M, int N);