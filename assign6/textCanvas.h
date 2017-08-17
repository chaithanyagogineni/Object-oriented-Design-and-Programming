//Header file named TEXTCANVAS_H
#ifndef TEXTCANVAS_H //Header guards
#define TEXTCANVAS_H
//including the header files
#include<string>
#include<iostream>
//declaring the standard namespace variables
using std::cout;
using std::string;
//Global symbolic constants.
const int CHEIGHT=24;
const int CWIDTH=80;
const int TC_OK=1;
const int TC_OUT_OF_BOUNDS=0;
const int TC_CURSOR_OUT_OF_BOX=0;
//This class contains array of CHEIGHT rows and CWIDTH columns and boundary 
class textCanvas
{
  char arr[CHEIGHT][CWIDTH];
  int cur_row,cur_col;
  int left_bound,right_bound,top_bound,bottom_bound;
 public:
  //default constructor
  textCanvas();
  //clear method used to clear data returns nothing,takes no arguments.
  void clear();
  //This method takes no arguments and returnss nothing
  void print() const;
  //This method is used to set the boundaries of the box
  //takes four integer arguments and returns integer
  int set_box(int a,int b,int c,int d);
  //This method is used to print the horizontal lines in the output
  //takes 3 arguments as integers and retruns an integer
  int print_horizontal_line(int a,int b,int c);
  //This method is used to print the vertical lines in the output
  //takes 3 integers as argument and returns integer
  int print_vertical_line(int a,int b,int c);
  //This method is used to print a character.
  //takes a character to print and returns an integer
  int print_char(const char c);
  //This method is used to send the characters of string to print_char() .
  //takes a string to print and returns an integer.
  int print_string(string s);
  
};
#endif //ENd of TEXTCANVAS_H
