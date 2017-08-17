#include<iostream>
#include<fstream>
#include<string>
#include "func.h"
using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::string;
int main(int argc, char* argv[])
{
    if(argc >= 3)                                                  /* Checking whether the Number of Arguements is less than 3 or not */
        {
            string input,output;
            input = argv[1];
            output = argv[2];
            ifstream in;
            ofstream out;
            in.open(input.c_str());                                 /* Opening Input File*/
            out.open(output.c_str());                               /* Opening Closing File*/
            if(in.is_open() && out.is_open())                       /* Checking whether the Input and Output Files are Open or Not */
                {
                    string line;
                    getline(in,line);
                    while(!in.eof())
                        {
                            getline(in,line);	                            /* Reading Line from Input File*/
                            process_data(line,out);                         /* Function to Displays Output */
                        }
                        in.close();
                        out.close();
                }
                else
                {
                    cerr<<"Could not open files"<<endl;                          /* Displaying Error Message */
                    return -1;
                }
         }
         else
        {
            cerr << "Less Number of Arguements. Please enter atleast 3 Arguements"<<endl;                            /* Displaying Error File */
            return -1;
        }
return 0;
}

