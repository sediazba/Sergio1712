#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <complex>
#include <algorithm>
void print_matrix(const std::vector<std::complex<double>> & matrix, int M, int N);
void fill_matrix_complex(std::vector<std::complex<double>> & matrix, const int M, const int N);
void pauli(const std::vector<double> & v, std::vector<std::complex<double>> & matrix_pauli);
void suma_matrix(const std::vector<std::complex<double>> & m1, const std::vector<std::complex<double>> & m2, std::vector<std::complex<double>> & resultado);