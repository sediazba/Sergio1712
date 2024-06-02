#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
void print_matrix(const std::vector<double> & matrix, int M, int N);
void fill_matrix(std::vector<double> & matrix, const int M, const int N);
void potencia_matrix(const std::vector<double> & matrix, const int M, const int p, std::vector<double> & B);
void multiplicacion_escalar(const int escalar, std::vector<double> & resultado, const int M);
void suma_matrix(std::vector<double> & suma, std::vector<double> & resultado, const int M);
void polynomial(const std::vector<double> & matrix, const std::vector<double> & vector_coefficients, std::vector<double> & resultado, std::vector<double> & suma,int M);