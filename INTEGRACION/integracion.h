#pragma once
#include<cmath>

using fptr = double(double);   //busca una funcion que reciba y retorne un double sin importar su nombre

using algptr = double(double, double, int, fptr);    //busca un algoritmo de integracion que devuelva un double y use dos double, un entero y una funcion

double trapezoid(double a, double b, int npoints, fptr fun); 

double simpson(double a, double b, int npoints, fptr fun);

double rich_inte(double a, double b, int npoints, fptr fun, algptr alg, int order);