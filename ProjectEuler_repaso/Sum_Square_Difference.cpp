#include <iostream>
#include <cmath>

int suma_de_cuadradros(void);
int cuadrado_de_la_suma(void);

int main(void)
{
    std::cout << (cuadrado_de_la_suma() - suma_de_cuadradros()) << "\n";
    return 0;
}

int suma_de_cuadradros(void)
{
    int i = 0;
    for(int a = 1; a <= 100; a = a + 1)
    {
        int b = std::pow(a, 2.0);
        i = i + b;
    }
    return i;
}

int cuadrado_de_la_suma(void)
{
    int ii = 0;
    for(int k = 1; k <= 100; k = k + 1)
    {
        ii = ii + k;
    }
    int c = std::pow(ii, 2);

    return c;
}