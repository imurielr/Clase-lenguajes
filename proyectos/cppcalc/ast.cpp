#include "ast.h"
#include <iostream>
#include "calculator.h"
#include "map.h"

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode::getSubTree() const {
   return subTree;
}

RShiftNode::RShiftNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

  int RShiftNode::evaluate(){
    return getLeftSubTree()->evaluate() >> getRightSubTree()->evaluate();
}

LShiftNode::LShiftNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

  int LShiftNode::evaluate(){
    return getLeftSubTree()->evaluate() << getRightSubTree()->evaluate();
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

 int AddNode::evaluate() {
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate() {
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int TimesNode::evaluate() {
   return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivideNode::DivideNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int DivideNode::evaluate() {
   return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

ModNode::ModNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

int ModNode::evaluate() {
  return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

StoreNode::StoreNode(AST* sub):
  UnaryNode(sub)
{}

int StoreNode::evaluate(){
  calc->store(getSubTree()->evaluate());
  return calc->recall();
}

PlusNode::PlusNode(AST* sub):
  UnaryNode(sub)
{}

int PlusNode::evaluate(){
  calc->plus(getSubTree()->evaluate());
  return calc->recall();
}

MinusNode::MinusNode(AST* sub):
  UnaryNode(sub)
{}

int MinusNode::evaluate(){
  calc->minus(getSubTree()->evaluate());
  return calc->recall();
}
				 
RecallNode::RecallNode() : AST() { }

int RecallNode::evaluate(){
  return calc->recall();
}

ClearNode::ClearNode() : AST() { }

int ClearNode::evaluate(){
  calc->clear();
  return calc->recall();
}

NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate() {
   return val;
}

SetNode::SetNode(AST* sub, string ident):
  UnaryNode(sub),
  id(ident)
{}

int SetNode::evaluate() {
  return env[id] = getSubTree()->evaluate();
}

IdentifierNode::IdentifierNode(string id):
  AST(),
  key(id)
{}

int IdentifierNode::evaluate(){
  return env[key];
}
