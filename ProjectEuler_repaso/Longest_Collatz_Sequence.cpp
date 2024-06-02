#include <iostream>
#include <cmath>

int counter_collatz_sequence(void);

int main(int argc, char **argv)
{
    std::cout << counter_collatz_sequence() << "\n";
    return 0;
}

int counter_collatz_sequence(void)
{
    int counter_max = 0;
    int valor_max = 0;

    for(int ii = 1; ii < 1000000; ii = ii + 1){

        int counter = 1;
        int valor_original = ii;

        while(ii != 1){
            if(ii % 2 == 0){
                ii = ii/2;
                counter += 1;
            }
            else {
                ii = (3 * ii) + 1;
                counter += 1;
            }   
        }
        
        if(counter > counter_max){
            counter_max = counter;
            valor_max = valor_original;
        }
    }
    return valor_max;
}