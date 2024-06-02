#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <complex>
#include <algorithm>
void print_matrix(const std::vector<std::complex<double>> & matrix, int M, int N);
void fill_matrix_complex(std::vector<std::complex<double>> & matrix, const int M, const int N);
void trans_matrix_complex(const std::vector<std::complex<double>> & matrix, std::vector<std::complex<double>> & matrixt, int M, int N);
bool check_hermitian_matrix(const std::vector<std::complex<double>> & matrix, int M, double eps);
void conjugado_matrix_complex(const std::vector<std::complex<double>> & matrix, std::vector<std::complex<double>> & conjugado, int M);
void multipl_matrix(const std::vector<std::complex<double>> & matrix, const std::vector<std::complex<double>> & matrixt, int M, int N, std::vector<std::complex<double>> & resultado);