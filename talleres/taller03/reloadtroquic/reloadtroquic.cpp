#include <iostream>

using namespace std;

void verificar();

int
main(void){
  verificar();
  return 0;
}

void verificar(){
  int buenas, malas;
  char amin = 97, amay = 65, zmin = 122, zmay = 90, vacio = 0;
  char cadena[60];
  cout << "Impresion de troquic: " << endl;
  cin >> cadena;

  for(int i=0; cadena[i]!=vacio; i+=2){
    if(cadena[i] >= amin && cadena[i] <= zmin){
      if(cadena[i+1] >= amay && cadena[i+1] <= zmay){
	++buenas;
      }
      else{
	cout << "Error en la baldosa numero: " << i/2+1 << endl;
	++malas;
      }
    }
    if(cadena[i] >= amay && cadena[i] <= zmay){
      if(cadena[i+1] >= amin && cadena[i+1] <= zmin){
	++buenas;
      }
      else{
	cout << "Error en la baldosa numero: " << i/2+1 << endl;
	++malas;
      }
    }
  }
  cout << "Numero de baldosas: " << buenas+malas << endl;
  cout << "Numero de baldosas buenas: " << buenas << endl;
  cout << "Numero de baldosas malas: " << malas << endl;
  return;
}
