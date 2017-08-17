/*This Assignemnt-7 is done by chaithanya Krishna G
Zid:Z1815642
T.A:Nithin Devang
CSCI689
Due-Date:04/18/2017
*/
//Including the header files required
#include "assign7.h"
#include "Pieces.h"
/*Main Function which takes 2 arguments
1.Integer argument:specifies number of arguments
2.Pointer to array of characters:This holds the command line arguments
*/
int main(int argc,char *argv[])
{
  //variable declarations
  string ex;
  //Declaring a set of Classes
  set<Pieces> set_of_pieces;
  //Error Checking For the Number of Arguments entered
  if(argc!=2)
    {
      cerr<<"\n USAGE:"<<argv[0]<<" "<<"input-file"<<"\n";
      return -1;
    }
  //Declaring the input file stream variable
  ifstream inp;
  //Opening the file for input
  inp.open(argv[1]);
  //Error Checking whether the file is opened Properly
  if(!inp.is_open())
    {
      cerr<<"\n Please make sure that the file exists \n";
      return -1;
    }
  //general variable declaration
  int space_found=0; //initially space found is 0
  string int_value="",str_value=""; //Initially set the integer value  and string value to empty strings
  //read the values from file until the file reaches the end  
  while(!inp.eof())
    {
      //reading single character
      char ch=inp.get();
      //If the charcter found found is not a space and space found is not set to 1
      if(ch!=' '&&space_found!=1)
	{
	  int_value=int_value+ch;
	}
      //If character is space,set the space found to 1
      else if(ch==' ')
	{
	  space_found=1;
	}
      //If the space found  is 1,and if the new line charatcer is found,then add the values of int_value and str_value to class and insert that instance to set
      else if(space_found==1)
	{
	  //If the new line character is found '10' is the ASCII value of new line
	  if(int(ch)==10)
	    {
	      //set the space found to zero
	      space_found=0;
	      //calling the parameterized constructor to initialise the values
	      Pieces p(std::stoi(int_value),str_value);
              //Inserting the instance into set
	      set_of_pieces.insert(p);
	      //setting the int_value and str_value to empty strings since after every new line ,we need sepearte integer and string values
	      int_value="";
	      str_value="";
	    }
	  //If it is not new line after the space found ,then add that character to the string
	  else
	    {
	      str_value=str_value+ch;
	    }
	}
      //If any of the above dont happen do nothing
      else
	{
	}
      
    }//End of While

  //Closing the file stream which is opened for input
  inp.close();
  
  cout<<"\n";//printing the new line character
  //USing iterator to get the values stored in set,use auto which will automatically declare the iterator required here
  for(auto i=set_of_pieces.begin();i!=set_of_pieces.end();++i)
    {
      //copying the string stored in the object into variable created above 
      ex=(*i)[1];  // here the overloaded subscript operator is called which returns a string

      //If the string is "\n" then print a new line character
      if(ex=="\\n")
	{
	  cout<<"\n";
	}
      //If the string is not a new line ,then print it
      else
	{
	  cout<<(*i)<<" ";
	}
    }
  cout<<"\n ";//printing new line after output
  return 0;
}
//end of main
