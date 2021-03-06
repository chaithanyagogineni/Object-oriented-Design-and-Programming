/*This Assignment is done by G.Chaithanya Krishna
ZID:Z1815642
Class:CSCI 689
Section:1
Date:01/26/2017
Computer Science*/
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cctype>
using std::setw;
using std::cout;
using std::cin;
using std::endl;
void display(float temp_high,float temp_low,float wind_low,float wind_high,int temp_dec,int wind_inc);
float windChill(float temp,float wind);
int main()
{
  float temp_high,temp_low,wind_low,wind_high;
  int temp_dec,wind_inc;
  cout<<"This program prints out a table of selected wind chill factors"<<endl;
 A:cout<<endl<<"Temperature range high value (degrees F)";
  cin>>temp_high;
  //performing Error Checking
  if(cin.fail())
    {
      cout<<endl<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 1;
    }
  cout<<endl<<"Temperature range low value (degrees F)";
  cin>>temp_low;
  //performing error checking
  if(cin.fail())
    {
      cout<<endl<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 1;
    }
  //Check whether temperature high value is greater than temperature low value
  if(temp_low>temp_high)
{
cout<<endl<<"PLEASE MAKE SURE THAT TEMPERATURE LOW VALUE SHOULD BE LESS THAN TEMPERATURE HIGH VALUE";
goto A;
}
B:cout<<endl<<"Temperature decrement (degrees F)";
 cin>>temp_dec;
 if(cin.fail())
    {
      cout<<endl<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 1;
    }
 //Check whether value is positive
 if(temp_dec<0)
{
cout<<endl<<"PLEASE ENTER POSITIVE DECREMENT VALUE";
goto B;
}
C:cout<<endl<<"Wind speed low value (mph)";
    cin>>wind_low;
    //perform error checking
    if(cin.fail())
    {
      cout<<endl<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 0;
    }
    if(wind_low<=0)
      {
	cout<<endl<<"please enter a posititve value";
	goto C;
      }
cout<<endl<<"Wind speed high value (mph)";
  cin>>wind_high;
  //perform error checking
  if(cin.fail())
    {
      cout<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 0;
    }
  if(wind_high<=0)
    {
      cout<<endl<<"please enter a positive value";
      goto C;
    }
  //check whther wind high is greater than wind low
  if(wind_high<wind_low)
{
cout<<endl<<"PLEASE MAKE SURE THAT WIND SPEED VALUE SHOULD BE FROM LOW TO HIGH ";
goto C;
}
D:cout<<endl<<"Wind speed increment (mph)";
  cin>>wind_inc;
  //perform error checking
  if(cin.fail())
    {
      cout<<endl<<"PLEASE ENTER VALUES NOT CHARACTERS OR STRINGS OR SYMBOLS";
	cout<<endl;
	return 0;
    }
if(wind_inc<0)
{
cout<<endl<<"PLEASE ENTER POSITIVE INCREMENT VALUE";
goto D;
} display(temp_high,temp_low,wind_low,wind_high,temp_dec,wind_inc);
  return 0;
}
/*This functions helps to display the temperatures ,wind speeds and the wind chill values associated with them.

It calls the windchill method in it*/
void display(float temp_high,float temp_low,float wind_low,float wind_high,int temp_dec,int wind_inc)
{
  float temp[100];
  float wind[100];
  int i=0,j=0;
  do
    {
      temp[i]=temp_high;
      temp_high=temp_high-temp_dec;
      i++;
    }while(temp[i-1]>=temp_low);
  cout<<endl<<"Wind Chill Table";
  cout<<endl<<"Air Temperature";
  cout<<endl<<"  (deg.F)";
  for(i=0;temp[i]>=temp_low;i++)
  {
    cout.precision(3);
    cout<<std::fixed<<setw(9)<<temp[i];
} 
 cout<<endl<<"----------------------------------------------------------------------------------------------------------------";
  cout<<endl<<"Wind speed";
  cout<<endl<<"(mph)"<<endl;
  do
    {
      wind[j]=wind_low;
      wind_low=wind_low+wind_inc;
      j++;
    }while(wind[j-1]<=wind_high);
  for(i=0;wind[i]<=wind_high;i++)
    {
      cout<<setw(9)<<wind[i];
      for(j=0;temp[j]>=temp_low;j++)
	{cout.precision(3);
	  cout<<setw(9)<<windChill(temp[j],wind[i]);
	}
      cout<<"\n";
    }
	   
}
/*This function calculates windchill.It takes two values
@param-float:one temperature vale
@param-float:one Wind Speed value
The function will calculate windchill value and returns it if temperature<50 and wind speed>3.
If any of the values are out of range,ity will return temperature value as Wind Chill value*/

float windChill(float temp,float wind)
{
  if(wind<=3||temp>=50)
    return temp;
  return (35.74+(0.6215*temp)-(35.75*pow(wind,0.16))+(0.4275*temp*pow(wind,0.16)));
}

