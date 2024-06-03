#pragma once
#include <iostream>
#include <cmath>

double function(double x);
double forward_deriv(double x, double h);
double central_deriv(double x, double h);
double rich_forward_deriv(double x, double h);
double rich_central_deriv(double x, double h);