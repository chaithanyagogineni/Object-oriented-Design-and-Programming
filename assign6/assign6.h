//This is header file created for assign6.cc(main file)
#ifndef ASSIGN6_H //header guards
#define ASSIGN6_H
//including the header files required
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
//including the classes required.
#include "Person.h"
#include "textCanvas.h"
//declaring the standard namespace variables
using std::cin;
using std::vector;
using std::cout;
using std::ifstream;
using std::string;
using std::stoi;
using std::cerr;
/*print_pedigree function declaration
This function takes 3 arguments
1.reference to textCanvas Class
2.reference to vector of Persons
3.integer which is the root of the current person
*/
void print_pedigree(textCanvas &tc, const vector<Person> & person,int root);
#endif //end of ASSIGN6_H header file
