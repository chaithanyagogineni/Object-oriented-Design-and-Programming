/*This is written by Chaithanya Krishna G.
Zid:Z1815642
Sec:0001
T.A:Nithin Devang
*/
/*Including the Header file named Class.h which consists
of Header files,standard namespace variable declarations,
class data members,constructors amd member functions
This file is written to implement the class member functions 
and constructors*/
#include "Class.h"  //Including the Header File
//Implementing the Default Constructor of Storm Class.It takes no arguments
Storm::Storm()
{
    name="None";
    basin='N';
    type='N';
    sequence=0;
    year=0;
    max_wind_speed=0;
    min_pressure=0;
}
//Implementing the Parameterized Constructor of Storm Class.It takes 6 arguments.4 integers,2 characters and a string 
Storm::Storm(int a,int b,int c,int d,char e,char f,string g)
{
    sequence=a;
    year=b;
    max_wind_speed=c;
    min_pressure=d;
    basin=e;
    type=f;
    name=g;
}
//Implementing the getType() of Storm class.It takes no argument and returns a character
char Storm:: getType() const 
{
    return type;
}
//implementing the getSequence() of Storm class.It takes no argument and returns an integer
int Storm:: getSequence() const
{
    return sequence;
}
//implementing the getYear() of Storm class.It takes no argument and returns an integer
int Storm:: getYear() const
{
    return year;
}
//implementing the getSpeed() of Storm class.It takes no argument and returns an integer
int Storm:: getSpeed() const
{
    return max_wind_speed;
}
//implementing the getPressure() of Storm class.It takes no argument and returns an integer
int Storm:: getPressure() const
{
    return min_pressure;
}
//implementing the print() of Storm class.It takes no argument and doesn't return anything
void Storm:: print() const
{
    cout<<setw(17);
    cout<<left;
    if(basin=='A')
        cout<<"Atlantic ";
    else if(basin=='E')
        cout<<"Eastern Pacific";
    else
        cout<<"Central Pacific ";
    cout<<setw(19)<<left;
    if(type=='H')
        cout<<"Hurricane";
    else if(type=='S')
        cout<<"Storm";
    else
        cout<<"Depression";
    cout<<setw(11)<<left;
    cout<<name;
    cout<<setw(2)<<right<<getSequence()<<"/"<<setw(6)<<left<<getYear();
    if(max_wind_speed!=-1)
        cout<<setw(6)<<right<<getSpeed();
    else
        cout<<setw(6)<<right<<" ";
    if(min_pressure!=10000)
        cout<<setw(5)<<right<<getPressure();
    else
        cout<<setw(5)<<right<<" ";
    cout<<"\n";
  
}
