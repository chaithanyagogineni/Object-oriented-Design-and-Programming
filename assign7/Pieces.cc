//Implementing the class named Pieces
//Including the header file for the Class Pieces
#include "Pieces.h"
//Implementing the Default constructor of class takes no arguments.
Pieces :: Pieces()
{
  int_value=0;
  str_value='\0';
}
//Implementing the paarameterized constructor of class takes 2 arguments integer and string
Pieces :: Pieces(int x,string y)
{
  int_value=x;
  str_value=y;
}
//Implementing the less than operator overloading
//takes 1 argument that is reference to const class Pieces
//returns boolean
//Since this is not modifying the current class instance.it is constant
bool Pieces :: operator <(const Pieces &ref1)const
{
 
  return (int_value<ref1.int_value);
  
}
//Implementing the subscripting operator of class
//takes one argument that is integer .
//Return the string that current instance is holding irrespective of the index passed
string Pieces :: operator [](int index)const
{
  return(*this).str_value;
  
}
//Implementing the output operator overloading,friend function
//Takes 2 arguments .one is reference to output stream and other is reference to constant class Pieces
//returns reference to output stream since we are chaining the output.
ostream& operator <<(ostream &ostr,const Pieces &ref)
{
  ostr<<(ref).str_value;
  return ostr;
}
//end of Class implementation
