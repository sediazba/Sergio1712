#include <iostream>

int palindrom_product(void);
bool verify_palindrom(int n);

int main(void)
{
    std:: cout << palindrom_product() << "\n";
    return 0;
}

int palindrom_product(void)
{
    int c = 0;
    int Largest_palindrom_product = 0;
    for(int k = 100; k <= 999; k = k + 1){
        for(int a = 100; a <= 999; a = a + 1){
            c = a * k;
            if(verify_palindrom(c) == true and c > Largest_palindrom_product){
                Largest_palindrom_product = c;
            }
        }
    }
    return Largest_palindrom_product;
}

bool verify_palindrom(int n)
{
    bool b = false; 
    int reverso = 0;
    int original = n;

    while(n != 0){
        int a = n % 10;

        reverso = reverso * 10 + a;

        n = n / 10;

        if(reverso == original){
           
        b = true;
        }
    }

    return b; 
}