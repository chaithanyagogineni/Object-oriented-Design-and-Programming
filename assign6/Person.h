//Header file of Person.cc
#ifndef PERSON_H //Header Guards
#define PERSON_H
//Including the header files required
#include "Date.h"
#include "Name.h"
#include "Place.h"
#include "textCanvas.h"
#include <iostream>
#include <string.h>
//declaring the standard namepsace variables
using std::string;
using std::cout;
/*This is Person class.
  It contains 9 data members of Type Name,Date,Place,int and 3 accessor methods and other member fucntion named print.*/
class Person
{
  Name first,last;
  Date bdate;
  Place bplace;
  Date ddate;
  Place dplace;
  int father,mother,child;
 public:
  //Default Constructor
  Person();
  //Parameterized constructor
  Person(Name a,Name b,Date c,Place d,Date e,Place f,int g,int h,int i);
  //Accessor method to get father value,takes no arguemnt and returns int
  int get_father() const;
  //Accessor method to get mother value,takes no argument and returns int
  int get_mother() const;
  //Accessor method to get child value .takes no arguemnt returns int
  int get_child() const;
  //Print method that takes reference to textCanvas class and return nothing
  void print(textCanvas& ref) const;
};
#endif //end of PERSON_H

