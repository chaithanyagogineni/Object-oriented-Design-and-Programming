/*This is a  Header file named Class_H
Written by Chaithanya Krishna G. 
Zid:Z1815642
CSCI689,Sec-0001
T.A:Nithin Devang
It consists of Class named Storm   and 
its default,Parameterized constructors, 
data memebers and member functions*/
#ifndef Class_H
#define Class_H
//Header Files Declaration 
#include<iostream>
#include<string>
#include<iomanip>
//Declaring Standard Namespace Variables
using std::cout;
using std::string;
using std::fixed;
using std::setw;
using std::left;
using std::right;
//Class named Storm
class Storm
{
    //data members 
    string name;
    char basin,type;
    int sequence,year,max_wind_speed,min_pressure;
 public:
    //constructors
    Storm();//default constructor with no arguments
    Storm(int a,int b,int c,int d,char e,char f,string g);//parameterized constructor with seven arguments 4 integers,2 Characters and a String
    //member Fucntions
    void print() const; //Functions that is used to print data.Takes no arguments.Doesn't return anything
    char getType() const;//Returns a character  i.e type of storm .takes no argument
    int getSequence() const;//returns integer which is a sequence number in the year.Takes no argument
    int getYear() const; //Returns integer,the  year in which the storm occured.Takes no argument
    int getSpeed() const; //returns integer,the speed of the storm.takes no argument
    int getPressure() const;//returns integer,the pressure of the storm.Takes no argument
};  //End of Class
#endif/*Class_H header file*/
