#include <iostream>

int suma(int a, int b);

int main(void)
{
    int a = -100, b = 1;
    std::cout << suma(a,b) << "\n";

    return 0;
}

int suma(int a, int b)
{
    int c = a + b;

    return c;
}