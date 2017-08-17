//header file of Date.cc
#ifndef DATE_H //Header guards
#define DATE_H
//including the header files required
#include "textCanvas.h"
#include<iostream>
#include<string>
//including the standard namespace variables
using std::cout;
using std::string;
//This the Date Clas which has 3 data members of type string and one member function print.
class Date
{
  string day,month,year;
 public:
  //default constructor
  Date();
  //Paramterized constructor
  Date(string a,string b,string c);
  //takes a textCanvas reference as a parameter
  void print(textCanvas& obj) const;
};
#endif //End of DATE_H
