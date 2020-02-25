
#pragma once

#include <string>

using namespace std;


class Calculator {
 public:
   Calculator();

   int eval(string expr);
   void store(int val);
   void plus(int val);
   void minus(int val);
   int recall();
   void clear();
   
 private:
   int memory;
};

extern Calculator* calc;
