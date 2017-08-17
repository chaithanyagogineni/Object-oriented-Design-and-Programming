/*This assignment is done by
Chaithanya Krishna G
ZID:Z1815642
CSCI-689
SEC-1
ASSIGNMENT--3
DUE DATE:02/17/2017*/
#include<iostream>
#include<cstdlib>
#include<fstream>
using std::cout;
using std::ofstream;
using std::cin;
using std::cerr;
int main()
{
    int rseed,num,max_value;
    char filename[50];
    int value=0;
    cout<<"\n Enter random number seed";
    cin>>rseed;
                                                    //Perform Error Checking
    cin.ignore(32767,'\n');                        //it checks whether there are any extra characters in buffer and ignore them until it encounters next line
    if(rseed<0||cin.fail())
    {
        cerr<<"\n Random Number Seed Must be Integer Positive Value\n";
	exit(1);                                   //Exits from the program
    }
    cout<<"\n Enter Maximum value for the random numbers to be generated";
    cin>>max_value;
                                                  //Perform Error Checking
    cin.ignore(32767,'\n');
    if(max_value<=0||cin.fail())
    {
        cerr<<"\n Maximum Value Must be a Integer Positive value\n";
        exit(1);                              //Exits from the program
    }
    cout<<"\n Enter the number of random values to be generated";
    cin>>num;
                                              //Perform Error Checking
    cin.ignore(32767,'\n');
    if(num<=0||cin.fail())
    {
        cerr<<"\n Number of values to be Generated should be Integer positive value\n";
        exit(1);                          //Exits from the program by returning 1 to operating system.
    }
    cout<<"\n Enter File Name";
    cin>>filename;
    ofstream mydata(filename);           //creates a new file and mydata is an instance of ofstream that opens new file and point to it.Takes filename as parameter.
    if(!mydata.is_open())               //is_open function checks whether the file pointed by mydata is opened or not.
    {
        cerr<<"\n unable to open the file "<<filename;
        exit(1);
    }
    srand(rseed);                    //srand function takes integer as an argument and it is used to initialize the random number generator
    for(int i=1;i<=num;i++)
    {
      value=(rand()%max_value);      //rand() functions takes no argument and it generates random number based on seed max_value is used to specify the highest range. 
      if(!mydata.eof())                //eof() functions checks whether the file pointed by mydata reached to its end or not.returns true if it reaches end else false.
	{
	    mydata<<value;
	    mydata<<" ";
	}
    }
    mydata.close();                     //After using the instance of ofstream,it should be closed.It closes the file pointed by mydata 
    return 0;
}
