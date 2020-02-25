#include <iostream>
#include "tresMayor.h"

using namespace std;

int tresMayor(int& a, int&b, int& c){
  if(a >= b && a >= c){
    cout << "El mayor es: " << a << endl;
  }
  else{
    if(b >= a && b >= c){
      cout << "El mayor es: " << b << endl; 
    }
    else{
      cout << "El mayor es: " << c << endl;
    }
  }
  return 0;  
}
