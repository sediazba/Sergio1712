#include "vectors.h"

double dot(const std::vector<double> & v1, const std::vector<double> & v2)
{
    double suma = 0.0;

    // v1.size() == v2.size()
    for(int ii = 0; ii < v1.size(); ++ii) {
        suma += v1[ii]*v2[ii];
    }

    return suma;
}