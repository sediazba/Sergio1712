#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
void print_matrix(const std::vector<double> & matrix, int M, int N);
void fill_matrix(std::vector<double> & matrix, const int M, const int N);
bool check_commute_matrix(const std::vector<double> & A, const std::vector<double> & B, int M, double eps);
void multipl_matrix(const std::vector<double> & matrix, const std::vector<double> & matrixt, int M, int N, std::vector<double> & resultado);