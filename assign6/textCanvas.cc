#include "textCanvas.h"
//default constructor that is used to initialise the members of the textCanvas class.
textCanvas::textCanvas()
{
  for(int i=0;i<CHEIGHT;i++)
    {
      for(int j=0;j<CWIDTH;j++)
	{
	  arr[i][j]=' '; //clearing all the array to spaces 
	}
    }
  //Setting the array current row and column to 0
  cur_row=0;
  cur_col=0;
  //Setting the bounding box boundaries to edges of the canvas
  left_bound=0;
  right_bound=CWIDTH;
  top_bound=0;
  bottom_bound=CHEIGHT;
}
//clear function takes no argument and returns nothing.Used to clear the canvas
void textCanvas:: clear()
{
  for(int i=0;i<CHEIGHT;i++)
    {
      for(int j=0;j<CWIDTH;j++)
	{
	  arr[i][j]=' '; //Clearing the array to spaces 
	}
    }
  //setting the cursor row,column to (0,0)
  cur_row=0;
  cur_col=0;
  //setting the bounds of the box.
  left_bound=0;
  top_bound=0;
  right_bound=CWIDTH;
  bottom_bound=CHEIGHT;
  
}
//This method prints the data in the array.This method takes no argument and returns nothing
void textCanvas:: print() const
{
  for(int i=0;i<CHEIGHT;i++)
    {
      for(int j=0;j<CWIDTH;j++)
	{
	  cout<<arr[i][j]; 
	}
      cout<<"\n";
    }
}
//This method is used to set the boundaries of the box
//Takes 4 integers as arguments and returns an integer
//First 2 arguments specify the x,y coordinates and next 2 specify width and height 
int textCanvas:: set_box(int a,int b,int c,int d)
{
  left_bound=a;
  top_bound=b;
  //Calculating right and bottom bounds
  right_bound=c+a;
  bottom_bound=d+b;
  //setting the current row and column of the cursor
  cur_row=b;
  cur_col=a;
   if(right_bound>CHEIGHT||bottom_bound>CWIDTH)
     return TC_OUT_OF_BOUNDS;//Returning TC_OUT_OF_BOUNDS if any error
  else
    return TC_OK;//Returing TC_OK,if it is With in the boundary.
  
  
}
//This method is used to print the horizontal line
//This method takes 3 arguments.
//First two speciy the starting position and ending position of the horizontal line third argument specify the length of line
int textCanvas:: print_horizontal_line(int a,int b,int c)
{
  
  for(int j=a;j<(a+c);j++)
    {
      arr[b][j]='-';
    }
  //Checking whether the x and  y coordiantes are with in the range
  if(b>CHEIGHT||a>CWIDTH)
    return TC_OUT_OF_BOUNDS;
  else
    return TC_OK;
}
//This method is used to print a vertical line
//Takes 3 int arguments.first 2 specify the x,y coordinates,3rd specify the length of vertical line
//returns an integer
int textCanvas:: print_vertical_line(int a,int b,int c)
{
  for(int j=b;j<(b+c);j++)
    {
      arr[j][a]='|';
    }
  //Checking whether x and y coordinates are with in the range 
   if(b>CHEIGHT||a>CWIDTH)
    return TC_OUT_OF_BOUNDS;
  else
    return TC_OK;
  
}
//This function is used to print the character to the array
//takes a constant character
//Returns aN INTEGER
int textCanvas:: print_char(const char c)
{
  //If next line increment the row
   if(c=='\n')
    {
      cur_row=cur_row+1;
          cur_col=left_bound;
      return TC_OK;
    }
   else if(c=='\r')
     {
       //This will not work with Linux file.
       // cur_col=left_bound;
       return TC_OK;
     }
  else
    {
      //If position is with in boundary,insert the character in to array
      if((cur_row<bottom_bound)&&(cur_col<right_bound))
	{
	  arr[cur_row][cur_col]=c;
	  cur_col=cur_col+1;
	  return TC_OK;
	}
      else
	return TC_CURSOR_OUT_OF_BOX;
    }
  
}
//This function takes string as argument and returns an integer
//returns every character of the string to print_Char() function
int textCanvas:: print_string(string s)
{
  int res;
  //Send every character of string for printing
  for(unsigned int i=0;i<s.size();i++)
    {
      res=print_char(s[i]);
    }
  //return the last value retruned by the print_char function
  return res;
}
