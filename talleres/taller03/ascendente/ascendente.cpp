#include <iostream>

using namespace std;

void secuencia();

int entrada = 0;

int
main(void){
  for(int i=0; i<=5; ++i){
    secuencia();
  }
  return 0;
}

void secuencia(){
  int a;
  cout << "Ingrese un numero: ";
  cin >> a;

  if((a - entrada) > 0){
    cout << " +" << endl;
    entrada = a;
  }
  else{
    cout << " -" << endl;
    entrada = a;
  }
  return;
}
