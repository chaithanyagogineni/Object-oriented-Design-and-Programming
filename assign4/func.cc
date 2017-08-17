#include "func.h"
bool flag = 0;
void process_data(const string input, ofstream& out)                         /* Function to Display Output File*/
{
    bool flag1 = 0 ,flag3 = 0;
    for(int i = 0 ; i < input.length();i++)                                  /* Processing*/
    {
        if(input[i] == '/' && input[i+1] == '*')                               
            {
                flag =1 ;
            }
        if(input[i] == '*' && input[i+1] == '/' && flag == 1 && input[i +2] != '/')
            {  
                flag =  0;
            }
         if(input[i] == '"')
            {
                if(flag3 == 0)
                    {
                        flag3 = 1;
                    }
                        else
                            {
                                flag3 = 0;
                            }
          if(input[i] == '/' && input[i+1] == '/' && flag3 != 1 && flag != 1)
              {
                  flag1 = 1;
                  i++;
                  out << "/*";
              }
          else
              {
                  out << input[i];                                           /* Displaying Output*/
              }
          if(flag1 == 1 && i == ((input.length()) -1) )
              {
                  out << "*/";
              }
              }
out << endl;
}
}


