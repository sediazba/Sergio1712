#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
void print_matrix(const std::vector<double> & matrix, int M, int N);
void fill_matrix(std::vector<double> & matrix, const int M, const int N);
void potencia_matrix(const std::vector<double> & matrix, const int M, const int p, std::vector<double> & B);