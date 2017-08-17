//including the header file Date.h
#include "Date.h"
//Implementing the Default constructor of Date class.
Date:: Date()
{
  day='\0';
  month='\0';
  year='\0';
}
/*Implementing the Parameterized constructor of Date Class.
This takes 3 arguments.
1.string-representing the day
2.string-representing the month
3.string-representing the year
*/
Date::Date(string a,string b,string c):day(a),month(b),year(c)
{

}
/*Implementing the print method of Date class.
This takes one argument
1.reference to textCanvas class
*/
void Date::print(textCanvas& obj) const
{
  obj.print_string(day);
  obj.print_string(" ");
  obj.print_string(month);
  obj.print_string(", ");
  obj.print_string(year);
}
