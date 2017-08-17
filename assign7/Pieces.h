//Header file for Pieces class
//Hedaer Guards
#ifndef PIECES_H
#define PIECES_H
//including the header files required
#include <iostream>
#include <string>
//declaring the standard namespace variables
using std::string;
using std::ostream;
//Class with data members integer,string and constructors
class Pieces
{
  //Private Data Members
  int int_value;
  string str_value;
  //Public members
  public:
  Pieces();//Default constructor
  Pieces(int x,string y);//parameterized constructor
  string operator [](int index)const;//subscript operator overloading that takes integer as an argument but doesn't use that
  bool operator <(const Pieces &ref1)const;//overloading comparison opeartor that takes 2 argument that are references to the Pieces class
  friend ostream& operator <<(ostream & ostr,const Pieces &ref);//Overloading output stram operator that takes 2 arguments that are reference to ostream and constant reference to Pieces class.This is a friend fucntion
  
};
#endif
//End of header file PIECES_H
