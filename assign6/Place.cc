//Including the header file for Place.cc
#include "Place.h"
//Implementing the default constructor of Place class
Place::Place()
{
  city=Name();
  county=Name();
  state=Name();
}
/*implementing the Parameterized constructor of Place Class
This takes 3 arguments
1.string representing city
2.string representing county
3.string representing state
*/
Place::Place(string a,string b,string c)
{
  city=Name(a);
  county=Name(b);
  state=Name(c);
}
/*Implementing the print method of Place class
This takes one argument
1.reference to textCanvas Class
*/
void Place:: print(textCanvas& obj)const
{
  city.print(obj);
  obj.print_string(", ");
  county.print(obj);
  obj.print_string(", ");
  state.print(obj);
}
