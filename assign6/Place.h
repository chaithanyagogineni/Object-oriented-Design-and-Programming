//Header file of Place.cc file
#ifndef PLACE_H //header guards
#define PLACE_H
//including the header files required
#include "textCanvas.h"
#include "Name.h"
#include<string>
//declaring the namespace variables
using std::string;
//Place class that has 3 members of Name type and member function Print.
class Place
{
  Name city,county,state;
 public:
  //Default constructor
  Place();
  //Parameterized constructor
  Place(string a,string b,string c);
  //Print method that takes reference to textCanvas class and returns nothing
 void print(textCanvas& obj) const;
};
#endif //end of PLACE_H
