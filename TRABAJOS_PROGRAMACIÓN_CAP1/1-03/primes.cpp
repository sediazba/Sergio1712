#include "primes.h"

bool isprime(int m)
{
    bool flag = true;
    for(int n = 2; n*n <= m; n++){  
            flag = false;
            break;
        }
    return flag;
}

