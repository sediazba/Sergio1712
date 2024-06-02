/*En la funcion tablealg_diff se distinguen muchas variables, los pesos 1, 2, 3 hacen referencia a los valores que aparecen en la tabla
de izquierda a derecha, como en los extremos son los mismos numeros con signos contrarios lo único que debe cambiar es el signo de cada uno,
por eso aparecen algunos definidos con signo - en la funcion main sin tenerlo en la tabla, es para ajustarlo a esta función, con el fin de 
usar solo una funcion para toda la tabla. Los c1, c2 y c3 se refieren a lo que acompaña a la h según el grado que aparece en la tabla.
*/
#include "derivacion.h"

long double tablealg_diff(long double x, long double h, long double peso1, long double peso2, long double peso3, long double c1, long double c2, long double c3, fptr fun)
{
    double a = (((-peso1) * fun(x + ((-c1) * h))) + ((-peso2) * fun(x + ((-c2) * h))) + ((-peso3) * fun(x + ((-c3) * h))) + (peso3 * fun(x + (c3 * h))) + (peso2 * fun(x + (c2 * h))) + (peso1 * fun(x + (c1 * h))))/h;
    return a;
}
/* En la extrapolacion de Richardson debemos incluir todas las variables, ademas de incertar las funciones correspondientes y el orden
que esta dado en la ultima columna de la tabla
*/
long double rich_diff(long double x, long double h, long double peso1, long double peso2, long double peso3, long double c1, long double c2, long double c3, fptr fun, algptr alg, int order) 
{
    long double t = 2.0;
    long double s1 = alg(x, h, peso1, peso2, peso3, c1, c2, c3, fun);
    long double s2 = alg(x, h/t, peso1, peso2, peso3, c1, c2, c3, fun);
    long double aux = std::pow(t, order);
    return (aux*s2 - s1)/(aux-1);  
}
