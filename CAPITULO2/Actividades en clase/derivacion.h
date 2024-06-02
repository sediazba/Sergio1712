#pragma once
#include <cmath>
using fptr = double(double);
using algptr = double(double x, double h, fptr fun);//representa a Forwardiff y centraldiff
double rich_diff(double x, double h, fptr fun, algptr alg, int order);
double forward_diff(double x, double h, fptr);
double central_diff(double x, double h, fptr fun);
/*double rich_forward_diff(double x, double h, fptr fun);
double rich_central_diff(double x, double h, fptr fun);*/