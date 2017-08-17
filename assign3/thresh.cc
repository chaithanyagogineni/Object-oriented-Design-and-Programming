/*This assignment is done by 
Chaithanya Krishna G
ZID:Z1815642
CSCI-689
SEC-1
DUE DATE-02/17/2017
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::vector;
using std::ifstream;
using std::cerr;
int main()
{
    std::vector<int> myarr;
    std::vector<int> temp;
    ifstream mydata;                                  //mydata is an instance of ifstream class
    char filename[50];
    int thresh_value;
    int value,flag=0;
    cout<<"\n enter the file name";
    cin>>filename;
    mydata.open(filename);                              //open function helps to open the file that is pointed by mydata
    if(!mydata.is_open())                               //is_open checks whether the file pointed by mydata is successfully opened or not
    {
        cerr<<"\ncannot open the file,Please make sure that file Exists \n";
	exit(1);
    }
    do
    {
        cout<<"\n enter thresh hold value";
	cin>>thresh_value;
	cin.ignore(32767,'\n');     //checks if there are any extra characters in buffer after reading input and ignores until it encounters a next line character '\n'
	flag=0;
	if(thresh_value<0)
	{
	    cerr<<"\n Make sure that u  enter positive value\n";
	    flag=1;
	}
	if(cin.fail())
	{
	    cerr<<"\n make sure u enter a positive integer value\n";
	    flag=1;
	    exit(1);
	 }
    }while(flag!=0);
    mydata>>value;
    while(!mydata.eof())               //eof() checks whether the file pointed by mydata has reached to end of file.
    {
        myarr.push_back(value);
	mydata>>value;

    }
    for(unsigned int i=0;i<myarr.size();i++)
    {
        if(myarr[i]>thresh_value)
	{
	    temp.push_back(myarr[i]);      //push_back() is a vector function that helps to insert element into it
	}
     }
	 
     mydata.close();                     //close() helps to close the file pointed by mydata
     cout<<"\n"<<temp.size()<<"  of "<<myarr.size()<<"  values in  "<<filename<<"  are greater than "<<thresh_value<<"\n";
     return 0;
}
