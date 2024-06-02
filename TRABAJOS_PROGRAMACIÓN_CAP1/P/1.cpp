%%writefile prime_factor.cpp
#include <iostream>
#include <cmath>
#include <string>

int second_largest_prime_factor(int a);
bool isprime (int b);
int closerprimefactor (int c);
long lowerclosestprimefactor (int d,int i);
bool isfactor (int f, int g);

int main(int argc,char **argv){
  std::cout << second_largest_prime_factor(std::stoi(argv [1])) << "\n";
}

int second_largest_prime_factor(int a){
int x = closerprimefactor(a);
int y = lowerclosestprimefactor(x,a);
return y;
}

//Ahora definimos la funcion isprime
bool isprime (int b){
  if (1 == b){
    return false;
  }
    bool flag = true;
    for (long ii=2 ; ii<=std::sqrt(b) ; ii++){
        if (b%ii == 0){
            flag = false;
            break;
        }
    }
    return flag;
}

//Ahora definimos la funcion closerfactor
int closerprimefactor (int c){
long jj = c;
  for(jj; jj<=c ;jj--){
      if(c%jj == 0 and isprime(jj) == true){
           break;
      }
  }
return jj;
}

//Ahora definimos la funcion closestprime
long lowerclosestprimefactor(int d,int i){
  if(i==18){long e = d;
  for (e ; isprime(e) == false ; e--){
  }
  if (isfactor(e,i) == true){
   return e;
  }
  lowerclosestprimefactor(e,i);
  }
  long e = d-1;
  for (e ; isprime(e) == false ; e--){
  }
  if (isfactor(e,i) == true){
   return e;
  }
  lowerclosestprimefactor(e,i);
}

//Ahora escribimos una funcion isfactor
bool isfactor (int f, int g){
  bool flag2 = true;
  if(g%f == 0){
    return flag2;
  }
  flag2 = false;
  return flag2;
}