#include <iostream>

int Find_min_multiple(void);
bool divisible(int n);

int main(void) 
{
    std::cout << Find_min_multiple() << "\n";
    return 0;
}

int Find_min_multiple(void)  
{
    int Smallest_Multiple = 0;
    for(int k = 0; ; k = k + 20){
        if(divisible(k) == true){
            Smallest_Multiple = k;
            break;
        }
    }
        
    return Smallest_Multiple;
}

bool divisible(int n)
{
    bool flag = true;
    for(int a = 2; a <= 20; a++){
        if(n == 0){
            flag = false;
            break;
        }
        if(n % a != 0){
            flag = false;
            break;
        }
    }
    return flag;
}