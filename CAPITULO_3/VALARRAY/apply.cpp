#include <iostream>
#include <valarray>
#include <cmath>

int main(void)
{
    std::valarray<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int ii = 0; ii < v.size(); ii = ii + 1){
        if(v[ii] % 2 == 0){
            v[ii] = 3 * v[ii];
        }else{
            v[ii] = 2 * v[ii];
        }
    }

    for(int ii = 0; ii < v.size(); ii = ii + 1){
        std::cout << v[ii] << "\t";
    }
    
    std::cout << "\n";

    std::valarray<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    v1 = v1.apply([](int n) -> int
                {
                    if(n % 2 == 0){
                        n = 3 * n;
                    } else{
                        n = 2 * n;
                    }
                    return n;
                });
    for (auto n : v1){
        std::cout << n << "\t";
    }
    std::cout << '\n';
}