#include <iostream>
#include "directand.h"

using namespace std;

bool directAnd(int a, int b){
  int c, d, e;
 
  cout << "Ingrese tres numeros enteros:" << endl;
  cin >> c >> d >> e;

  a = c - d;
  b = d - e;
  
  if(a  > 0 && b > 0){
    cout << "a y b son mayores que cero" << endl;
  }
  
  cout << " a: " << a
       << " b: " << b
       << endl;
  return false;
}
