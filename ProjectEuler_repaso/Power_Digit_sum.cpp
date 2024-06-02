#include <iostream>
#include <cmath>
#include <vector>

int main(int argc,char** argv)
{
    int n = std::stoi(argv[1]);
    long double m = std::pow(2.0, n);
    std::vector <int> digits;

    std::cout << m << "\n";

    while (m > 0) {
        int digit = static_cast<int>(std::fmod(m, 10));

        digits.insert(digits.begin(), digit);

        m = std::trunc(m / 10);
    }

    long double suma = 0;
    for (int ii = 0; ii <= digits.size(); ii = ii + 1) {
        suma = suma + digits[ii];
    }
    std::cout << suma << "\n";

    return 0; 
}