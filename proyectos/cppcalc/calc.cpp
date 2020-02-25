#include <iostream>
#include <sstream>
#include <string>
#include "calcex.h"
#include "calculator.h"
#include "map.h"
using namespace std;

Calculator* calc;

int main(int argc, char* argv[]) {
  string line;
   
  calc = new Calculator();

  cout << "> ";
   while(getline(cin, line)){
     try{
	 
       line += '\n';
       
       //calc = new Calculator();
       
       int result = calc->eval(line);
	 
       cout << "= " << result << endl;

       //delete calc;
       
       cout << "> ";
     }
     catch(Exception ex) {
       //cout << "* Program Aborted due to exception!" << endl;
       cout << "> ";
     }
   }
}
