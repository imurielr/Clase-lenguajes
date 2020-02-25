#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>

Parser::Parser(istream* in) {
   scan = new Scanner(in);
}

Parser::~Parser() {
   try {
      delete scan;
   } catch (...) {}
}

AST* Parser::parse() {
   return prog();
}

AST* Parser::prog() {
   AST* result = bitExpr();
   Token* t = scan->getToken();

   return result;
}


AST* Parser::bitExpr(){
  return restBitExpr(expr());
}

AST* Parser::restBitExpr(AST* e){
  Token* t = scan->getToken();

  if(t->getType() == lShift) {
    return restBitExpr(new LShiftNode(e,expr()));
  }

  if(t->getType() == rShift){
    return restBitExpr(new RShiftNode(e,expr()));
  }

   scan->putBackToken();
   
   return e;
}

AST* Parser::expr() {
   return restExpr(term());
}

AST* Parser::restExpr(AST* e) {
   Token* t = scan->getToken();

   if (t->getType() == add) {
      return restExpr(new AddNode(e,term()));
   }

   if (t->getType() == sub)
      return restExpr(new SubNode(e,term()));

   scan->putBackToken();
   
   return e;
}

AST* Parser::term() {
  return restTerm(storable());
}

AST* Parser::restTerm(AST* e) {
  Token* t = scan->getToken();

  if(t->getType() == times){
    return restTerm(new TimesNode(e, storable()));
  }

  if(t->getType() == divide){
    return restTerm(new DivideNode(e, storable()));
  }

  if(t->getType() == mod){
    return restTerm(new ModNode(e, storable()));
  }

  scan->putBackToken();

  return e;
}

AST* Parser::storable() {
  AST* result = factor();

  Token* t = scan->getToken();

  if(t->getType() == keyword){
    if(t->getLex() == "S"){
      return new StoreNode(result);
    }
    else if(t->getLex() == "P"){
      return new PlusNode(result);
    }
    else if(t->getLex() == "M"){
      return new MinusNode(result);
    }
    else{
      cout << "* Parser error: Expected S or P or M found: "
	   << t->getLex() << endl;
      throw ParseError;
    }
  }
  
  scan->putBackToken();
  
  return result;
}

AST* Parser::factor() {
  Token* t = scan->getToken();
  
   if (t->getType() == number) {
      istringstream in(t->getLex());
      int val;
      in >> val;
      return new NumNode(val);
   }
   else if (t->getType() == identifier){
     return new IdentifierNode(t->getLex());
   }
   else if(t->getType() == keyword){
     if(t->getLex() == "R"){
       return new RecallNode();
     }
     else if(t->getLex() == "C"){
       return new ClearNode();
     }
     else if(t->getLex() == "set"){
       t = scan->getToken();
       if(t->getType() != identifier){
	 cout << "* Parser error: Expected identifier" << endl; 
	 throw ParseError;
       }
       string id = t->getLex();
       t = scan->getToken();
       if(t->getType() != equals){
	 cout << "* Parser error: Expected =" << endl;
	 throw ParseError;
       }
       AST* result = bitExpr();
       return new SetNode(result, id);  
     }
     else{
     cout << "* Parser error: Expected R, C or set found: "
	  << t->getLex() << endl;
     throw ParseError;
     }
   }
   else if(t->getType() == lparen){
     AST* result = bitExpr();
     t = scan->getToken();
    
     if(t->getType() == rparen){
       return result;
     }
     else{
       cout << "* Parser error: Expected )"
	    << endl;
       throw ParseError;
     }
   }
   
   cout << "* Parser error: Expected Number, 'R', 'C', '('"
	<< endl;
   throw ParseError;
}
