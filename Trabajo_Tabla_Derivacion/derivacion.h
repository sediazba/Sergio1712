#pragma once
#include <cmath>

using fptr = long double(long double);
//algptr alg es la funcion que hace la derivacion que vamos a darle, en este caso solo hay 1 tablealg_diff
using algptr = long double(long double x, long double h, long double peso1, long double peso2, long double peso3, long double c1, long double c2, long double c3, fptr fun); 
long double tablealg_diff(long double x, long double h, long double peso1, long double peso2, long double peso3, long double c1, long double c2, long double c3, fptr fun);
long double rich_diff(long double x, long double h, long double peso1, long double peso2, long double peso3, long double c1, long double c2, long double c3, fptr fun, algptr alg, int order);