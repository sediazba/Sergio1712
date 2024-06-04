#pragma once
#include <iostream>
#include <cmath>

using fptr = double(double);
using algptr = double(double a, double b, double N, fptr fun);

double function(double x);
double trapezoid(double a, double b, double N, fptr fun);
double simpson(double a, double b, double N, fptr fun);
double richardson(double a, double b, double N, algptr alg, fptr fun, int orden);