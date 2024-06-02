#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
void print_matrix(const std::vector<double> & matrix, int M, int N);
void fill_matrix_random(std::vector<double> & matrix, const int M, const int N, const int seed);
double trace_matrix(const std::vector<double> & matrix, int M, int N);