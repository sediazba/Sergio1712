#pragma once
#include <cmath>

using fptr = double(double);
using algptr = double(double, double, int, fptr); 
double trapezoid(double a, double b, int npoints,  fptr fun);
double simpson(double a, double b, int npoints,  fptr fun);
double rich_intr(double a, double b, int npoints, fptr fun, algptr alg, int order);