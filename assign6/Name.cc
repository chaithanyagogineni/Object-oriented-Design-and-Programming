//Including the header file
#include "Name.h"
//Implementing the Default constructor of Name class
Name:: Name()
{
   name="";  
}
//implementing the parameterized constructor of Name class
Name:: Name(string a):name(a)
{
 
}
/*Implementing the print method of Name class
This takes 1 argument
1.reference to textCanvas Class
*/
void Name:: print(textCanvas& obj) const
{
  obj.print_string(name);//Printing the data member to print_string of textCanvas class
 
}
