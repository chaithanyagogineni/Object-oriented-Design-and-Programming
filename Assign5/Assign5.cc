/*This assignment is done by 
G.Chaithanya Krishna
Z1815642
T.A: Nithin Devang
CSCI 689 Sec-1
Due date:03/10/2017
*/
//Declaring Header Files 
#include<fstream>
#include<vector>
#include<unistd.h>
//including Class.h Header file
#include "Class.h"
//Declaring standard namespace declarations
using std::ifstream;
using std::cin;
using std::vector;
using std::cerr;
using std::stoi;
//Function Prototype declarartions
void sortByDate(vector<Storm> &sbd);//method that takes reference of vector as argument and returns nothing.
bool compareDate(Storm const &st1,Storm const &st2);//method that takes 2 references to constant storm class  as argument and returns boolean.
void sortBySpeed(vector<Storm> &sbs);//method that takes reference of vector as argument and returns nothing.
void sortByPressure(vector<Storm> &sbp);//method that takes reference of vector as argument and returns nothing.
void printHeader();//Method used to print header of output .Takes no argument and returns nothing
void print(const vector<Storm> &p); //This functions takes reference to constant storm and calls the print method of storm class.
void inputData(ifstream& inp,Storm &st);//Function takes 2 parameters. one is file input stream and reference tostorm class.read data and store in storm class. 
static vector<Storm> arr;
int main(int argc,char *argv[])
{
    int j=0;
    static ifstream inp;
    //Checking for correct Usage
    if(argc!=2)
        {
	    cerr<<"\n Usage: "<<argv[0]<<" [InputFile] \n";
	    return -1;
      }
    inp.open(argv[1]);
    //Checking Whether or not the file is opened Correctly
    if(!inp.is_open())
        {
	    cerr<<"\nUnable to open the file \n";
	    return -1;
	}
    do
        {
	    inputData(inp,arr[j]);//Calling Input function Until end of file
	    j++;
	}while(!inp.eof());
    inp.close();//closing the file
    cout<<"\n"<<arr.size()<<" Storms read from "<<argv[1]<<"\n";
    print(arr); //Calling the Print function,Which in turn calls the print function of class to display the data of vector of storm class.
    sortByDate(arr);//calling the function to sort and display the sorted data by increasing date
    sortBySpeed(arr);//calling the function to sort and display the sorted data by decreasing speed
    sortByPressure(arr);//calling the function to sort and display the sorted data by increasing pressure 
    return 0;
}
/*print function that takes reference to  
const vector of storms and returns nothing
used to call the print fucntion of each class in vector
also keeps track of number of lines printed and 
calls printHeader() appropriately*/
void print(const vector<Storm> &p)
{
    int num=0;
    const int max_lines=20;//Symbolic constant used to check num of lines crosses this
    vector<Storm>:: const_iterator i;
    for(i=p.cbegin();i!=p.cend();++i)
        {
	    if((num%max_lines)==0)
	        printHeader();
      
	    (*i).print();
	    num++;     
	}
 
}
/*This function takes no arguments and returns nothing
  This is invoked when print() method calls it*/
void printHeader()
{
    cout<<"\n";
    cout<<setw(36);
    cout<<left<<"Storm";
    cout<<setw(13);
    cout<<left<<"Name";
    cout<<setw(9);
    cout<<left<<"Date";
    cout<<setw(5);
    cout<<left<<"Wind";
    cout<<setw(5);
    cout<<left<<"mbar";
    cout<<"\n";
    cout<<"-------------------------------------------------------------------\n";
}
/*This function takes 2 parameters.
1.Input File stream
2.reference to Storm instance
returns nothing
used to get data into each storm single line at a time*/
void inputData(ifstream& inp,Storm &st)
{
    //Flags that helps to know the Processing of data
    int basin_processed=0;
    int name_processed_start=0;
    int name_processed_end=0;
    int sequence_processed_start=0;
    int sequence_processed_end=0;
    int year_processed_start=0;
    int year_processed_end=0;
    int speed_processed_start=0;
    int speed_processed_end=0;
    int pressure_processed_start=0;
    int pressure_processed_end=0;
    int type_processed=0;
    int space_found=0;
    char type,basin;
    string name;
    string sequence,year,max_wind_speed,min_pressure;
    char temp=inp.get();
    int data_processed=0;//variable declared to check whether the data is processes or not
    //get the value from file
    //Performs the looping until it encounters Next line or end of file.
    while((temp!='\n')&&(!inp.eof()))
        {
	  // set the space_found flag,if space is encountered
          if((temp==char(9))||(temp==char(32)))
	      {
		  space_found=1;
	      }
	  else
	    {
	      space_found=0;
	    }
	  //set the basin_processed flag ,if basin is processed
	  if((basin_processed!=1)&&(space_found==0))
	      {
		  basin=temp;
		  basin_processed=1;
		  data_processed=1;//set the data processed to 1
	      }
	  //process the name if you have not encountered a space and haven't processed name
	  else if((name_processed_end!=1)&&(space_found==0))
	      {
 		  name+=temp;
		  name_processed_start=1;
	
	      }
	  else if((name_processed_start==1)&&(space_found==1))
	      {
		  name_processed_end=1;
		  name_processed_start=0;
	      }
	  //process the sequence,if space is not encountered and sequence is not processed
	  else if((sequence_processed_end!=1)&&(space_found==0))
	      {
		  sequence+=temp;
		  sequence_processed_start=1;
	      }
	  else if((sequence_processed_start==1)&&(space_found==1))
	      {
		  sequence_processed_end=1;
		  sequence_processed_start=0;
	      }
	  //process the year,if space is not encountered and year is not processed
	  else if((year_processed_end!=1)&&(space_found==0))
	      {
		  year+=temp;
		  year_processed_start=1;
	      }
	  else if((year_processed_start==1)&&(space_found==1))
	      {
		  year_processed_end=1;
		  year_processed_start=0;
	      }
	  //process the speed,if space is not encountered and speed is not processed
	  else if((speed_processed_end!=1)&&(space_found==0))
	      {
		  max_wind_speed+=temp;
		  speed_processed_start=1;
	      }
	  else if((speed_processed_start==1)&&(space_found==1))
	      {
		  speed_processed_end=1;
		  speed_processed_start=0;
	      }
	  //process the pressure,if space is not encountered and pressure is not processed
	  else if((pressure_processed_end!=1)&&(space_found==0))
	      {
		  min_pressure+=temp;
		  pressure_processed_start=1;
	      }
	  else if((pressure_processed_start==1)&&(space_found==1))
	      {
		  pressure_processed_end=1;
		  pressure_processed_start=0;
	      }
	  //process the type,if space is not encountered and type is not processed
	  else if((type_processed!=1)&&(space_found==0))
	     {
	         type=temp;
		 type_processed=1;
	     }
	  temp=inp.get();//get the next value from file
	}
     //using stoi() to convert a string into integer and pushing the object of storm class int vector by invoking parameterized constructor
    //push into vector only if data is processed
    if(data_processed==1)
    arr.push_back(Storm(stoi(sequence),stoi(year),stoi(max_wind_speed),stoi(min_pressure),basin,type,name));
    return ;
}
/*This functions is used to sort the data stored in objects of vector of storms by increasing order of pressure
uses Bubble Sort technique
Takes 1 Argument:reference to Vector of Storm
returns nothing
*/
void sortByPressure(vector<Storm> &sbp)
{
    vector<Storm>:: iterator i1;
    vector<Storm>:: iterator i2;
    Storm st;
    //uses bubble sort technique to sort
    for(i1=sbp.begin();i1!=sbp.end();++i1)
        {
	    for(i2=sbp.begin();i2!=sbp.end()-1;++i2)
	        {
	 
		    if((*i2).getPressure()>(*(i2+1)).getPressure())
		        {
			    st=*i2;
			    *i2=*(i2+1);
			    *(i2+1)=st;
	                }
	  
		}
	}
    cout<<"\nSort by pressure:\n";
    print(sbp);//Passing the vector of storms by Calling the print method to display the sorted data 
}
/*This functions is used to sort the data stored in objects of vector of storms by decreasing  order of speed
uses Bubble Sort technique
Takes 1 Argument:reference to Vector of Storm
returns nothing
*/
void sortBySpeed(vector<Storm> &sbs)
{
    vector<Storm>:: iterator i1;
    vector<Storm>:: iterator i2;
    Storm st;
    //using the Bubble sort technique
    for(i1=sbs.begin();i1!=sbs.end();++i1)
        {
	    for(i2=sbs.begin();i2!=sbs.end()-1;++i2)
	        {
	 
		    if((*i2).getSpeed()<(*(i2+1)).getSpeed())
		        {
			    st=*i2;
			    *i2=*(i2+1);
			    *(i2+1)=st;
	                }
	  
	        }
	}
    cout<<"\nSort by wind speed:\n";
    print(sbs);//Passing the vector of storms by Calling the print method to display the sorted data
}
/*This function is used to compare 2 Storm objects date 
It takes 2 parameters.2 references to const storm classes
return type:boolean
returns true if first date is less than the second date
*/
bool compareDate(Storm const &st1,Storm const &st2)
{
    if(st1.getYear()<st2.getYear())
    return true;
    else if(st1.getYear()==st2.getYear())
        {
	    if(st1.getSequence()<st2.getSequence())
	        {
		    return true;
	        }
        }
    return false;
}
/*This function is used to sort the data stored in objects of vector of storms by increasing order of date
uses Bubble Sort technique
Takes 1 Argument:reference to Vector of Storm
returns nothing
*/
void sortByDate(vector<Storm> &sbd)
{
    vector<Storm>:: iterator i1;
    vector<Storm>:: iterator i2;
    bool temp;
    Storm st;
    //Bubble sort Technique
    for(i1=sbd.begin();i1!=sbd.end();++i1)
        {
	    for(i2=sbd.begin();i2!=sbd.end()-1;++i2)
	        {
		    temp=compareDate((*i2),*(i2+1));//Calling the compareDate Function to check whether First date is less than the second date
		    if(temp==0)
		        {
			    st=*i2;
			    *i2=*(i2+1);
			    *(i2+1)=st;
			}
	  
		}
	}
    cout<<"\nSort by date:\n";
    print(sbd);//Passing the vector of storms by Calling the print method to display the sorted data
}
