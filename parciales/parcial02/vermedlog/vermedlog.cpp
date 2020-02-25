#include <iostream>

using namespace std;

void comprobar(int a, int b);

void compcont(string ast, int a);

int cont;

int
main(void){
  int base, n;
  string comp;
  cin >> base >> n;
  
  comprobar(base, n);

  cin >> comp;

  compcont(comp, base);
}

void comprobar(int a, int b){
  int entero;
  string ast, ast0;
  
  for(int i=0; i < b; ++i){
    cin >> entero >> ast;

    if(entero % a == 0){
      ast0 = "*";
      ++cont;
    }
    else if(entero % a == 1){
      ast0 = "**";
      cont += 2;
    }
    else if(entero % a == 2){
      ast0 = "***";
      cont += 3;
    }
    
    if(ast.size() == ast0.size()){
      cout << "=" << endl;
    }
    else if(ast.size() < ast0.size()){
      cout << "<" << endl;
    }
    else if(ast.size() > ast0.size()){
      cout << ">" << endl;
    }
  }
  if(cont % a == 0){
      ast0 = "*";
      ++cont;
    }
  else if(cont % a == 1){
    ast0 = "**";
    cont += 2;
  }
  else if(cont % a == 2){
    ast0 = "***";
    cont += 3;
  }
}

void compcont(string ast, int a){
  string ast0;
  if(cont % a == 0){
      ast0 = "*";
  }
  else if(cont % a == 1){
    ast0 = "**";
  }
  else if(cont % a == 2){
    ast0 = "***";
  }
  if(ast.size() == ast0.size()){
      cout << "=" << endl;
    }
    else if(ast.size() < ast0.size()){
      cout << "<" << endl;
    }
    else if(ast.size() > ast0.size()){
      cout << ">" << endl;
    }
}
