//Header file for assign8.cc
#ifndef ASSIGN8_H
#define ASSIGN8_H
#include "Amenity.h"
#include "AmenityHelper.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iomanip>
using std::cerr;
using std::ifstream;
using std::vector;
using std::string;
using std::getline;
int input(string file_name,vector<Amenity> &ref);
void Composite_amenity(vector<Amenity> &ref);
#endif
//end of ASSIGN_8 header file
