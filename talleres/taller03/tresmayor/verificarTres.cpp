#include <iostream>
#include <limits>
#include "tresMayor.h"

using namespace std;

void leerEntero(int&);

int
main(void){
  int a;
  int b;
  int c;

  for(int i = 0; i < 4; ++i){
    cout << "Ingrese el primer numero" << endl;
    leerEntero(a);

    cout << "Ingrese el segundo numero" << endl;
    leerEntero(b);

    cout << "Ingrese el ultimo numero" << endl;
    leerEntero(c);

    tresMayor(a, b, c);
  }
  return 0;
}

void leerEntero(int& entero){
  cin >> entero;

  while(cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits < streamsize >::max(), '\n');
    cout << "Ingrese un numero valido" << endl;
    cin >> entero;
  }
  return ;
}
