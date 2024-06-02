#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <complex>
#include <algorithm>
void print_matrix(const std::vector<std::complex<double>> & matrix, int M, int N);
void commute_matrix_pauli(double eps);
bool check_commute_matrix_complex(const std::vector<std::complex<double>> & A, const std::vector<std::complex<double>> & B, int M, double eps);
void multipl_matrix_complex(const std::vector<std::complex<double>> & matrix, const std::vector<std::complex<double>> & matrixt, int M, int N, std::vector<std::complex<double>> & resultado);