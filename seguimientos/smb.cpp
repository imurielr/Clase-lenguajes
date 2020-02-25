#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int
main(int argc, char *argv[]){

  for(int i = 0; i < argc; ++i){
    string file = argv[i];

    ifstream input(file);

    int v, l, vCont = 0, lCont = 0;
    while(input >> v >> l){
      vCont += v;
      lCont += l;
    }

    if(vCont > lCont){
      cout << "Juego: " << file << " ganó visitante" << endl;
    }
    if(vCont < lCont){
      cout << "Juego: " << file << " ganó local" << endl;
    }
    if(vCont == lCont){
      cout << "Empate: " << file << endl;
    }
  }
  return 0;
}
