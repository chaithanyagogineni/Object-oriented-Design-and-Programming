//Header file of Name Class
#ifndef NAME_H //Header Guards
#define NAME_H
//Including the header files required 
#include "textCanvas.h"
#include<iostream>
#include<string>
//Including the namespace standard variables
using std::string;
using std::cout;
//This class has one datamember of type string and one print Method.
class Name
{
  string name;
 public:
  //Default constructor
  Name();
  //paraeterized constructor
  Name(string a);
  //Print method takes a reference to textCanvas class returns nothing
 void print(textCanvas& obj) const;
};
#endif //End of NAME_H
