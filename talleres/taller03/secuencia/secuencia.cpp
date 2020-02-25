#include <iostream>

using namespace std;

void leer();

int
main(void){
  leer();
  return 0;
}

void leer(){
  float prom, factor, value;
  int num;

  cout << "¿Cuantos valores va a ingresar? ";
  cin >> num; 
  cout << endl;

  cout << "Ingrese el factor de crecimiento: ";
  cin >> factor;
  cout << endl;

  for(int i=1; i<=num; ++i){
    cout << "Valor: ";
    cin >> value;

    if(value > prom){
      prom = (prom + value / factor)/i;
    }
    else{
      prom = (prom + value * factor)/i;
    }
    cout << "PROMEDIO: " << prom; 
    cout << endl;
  }
}
