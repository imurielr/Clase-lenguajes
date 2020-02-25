#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
 
int toInt(const char *str);

int
main(int argc, char *argv[]){
  int num, f, s, m;
  int res = toInt(argv[1]);
  for(int i = 2; i < argc; ++i){
    ifstream input(argv[i]);
    
    while(input >> num){
      f += num % res;       
      s += f % res;
    }
    
    cout << f % res << endl;
    m = s % res;
  }
  cout << m << endl;
}

int toInt(const char *str){
  string s(str);
  istringstream iss(s);

  int valor;

  iss >> valor;

  return valor;
}
