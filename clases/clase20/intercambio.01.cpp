#include <iostream>
#include <cstdlib>

using namespace std;

void intercambiar(int a, int b){
  int tmp = a;
  a = b;
  b = tmp;
}

int
main(void){
  int k = 10, j = 20;

  cout << "k: " << k << " j: " << j << endl;

  intercambiar(k,j);

  cout << "k: " << k << " j: " << j << endl;

  return EXIT_SUCCESS;
}
