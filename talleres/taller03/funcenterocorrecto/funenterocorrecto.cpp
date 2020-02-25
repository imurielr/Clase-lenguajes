#include <iostream>
#include <limits>

using namespace std;

int leerEnteroCorrecto(int&);

int
main(void){
  int a;
  cout << "Leer a" << endl;
  leerEnteroCorrecto(a);

  int b;
  cout << "Leer b" << endl;
  leerEnteroCorrecto(b);

  cout << " a: " << a
       << " b: " << b
       << endl;

  return 0;
  
}

int leerEnteroCorrecto(int& entero){
  cin >> entero;
  
  while (cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits< streamsize >::max(), '\n');
    cout << "Ingrese un numero valido: ";
    cin >> entero;
  }
  return 0;
}
