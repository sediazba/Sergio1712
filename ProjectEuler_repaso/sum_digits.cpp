#include <iostream>
#include <string>

int suma_digitos(int n);

int main(int argc, char **argv)
{
    int n = std::stoi(argv[1]);
    suma_digitos(n);
    //std::cout << suma_digitos(n) << "\n";
    return 0;
}

int suma_digitos(int n)
{
    int a = 0;

    while (n != 0)
    {
        a = n%10;
        n = n/10;

        std::cout << a << "\n";
    }
    return a;
}
