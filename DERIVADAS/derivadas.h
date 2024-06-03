#pragma once
#include <iostream>
#include <cmath>

using fptr = double(double);
using algptr = double(double x, double h, fptr);

double function(double x);
double forward_deriv(double x, double h, fptr fun);
double central_deriv(double x, double h, fptr fun);
double richardson_deriv(double x, double h, algptr alg, int orden);