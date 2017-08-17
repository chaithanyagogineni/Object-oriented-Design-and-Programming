//Including the header file of Person.cc class
#include "Person.h"
//Implementing the default constructor of Person Class
Person:: Person()
{

  father=-1;
  mother=-1;
  child=-1;
  first=Name();
  last=Name();
  bdate=Date();
  bplace=Place();
  ddate=Date();
  dplace=Place();
  
}
/*Implementing the parameterized constructor of Person class
This takes 9 paraeters
1.Name type-representing first name
2.Name type-representing last name
3.Date type-representing birth date
4.Place type-representing birth place
5.Date type-representing death date
6.Place type-representing the death place
7.integer-representing the root of father
8.integer=-representing the root of mother
9.integer-representing the root of child
*/
Person:: Person(Name a,Name b,Date c,Place d,Date e,Place f,int g,int h,int i)
{

  father=g;
  mother=h;
  child=i;
  first=a;
  last=b;
  bplace=d;
  bdate=c;
  ddate=e;
  dplace=f;
  
}
/*This function takes no arguments and returns an integer i.e root of father*/
int Person:: get_father() const
{
  return father;
}
/*This function takes no arguments and returns an integer i.e root of mother*/
int Person:: get_mother() const
{
  return mother;
}
/*This function takes no arguments and returns an integer i.e root of Child*/
int Person:: get_child() const
{
  return child;
}
/*This method takes an argument
1.reference to  textCanvas Class
returns nothing*/
void Person:: print(textCanvas& obj) const
{
  first.print(obj);
  obj.print_string(", ");
   last.print(obj);
  obj.print_string("\nb. ");
  bdate.print(obj);
  obj.print_string("\n");
  obj.print_string("   ");
  bplace.print(obj);
  obj.print_string("\nd. ");
  ddate.print(obj);
 obj.print_string("\n");
 obj.print_string("   ");
  dplace.print(obj);
  
}
