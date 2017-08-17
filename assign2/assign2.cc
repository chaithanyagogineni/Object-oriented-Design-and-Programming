/*This is Assignment-2 done by
Name:G.Chaithanya Krishna 
ZID:Z1815642
Class:CSCI 689
SEC:1
Date:02/07/2017
*/

#include<iostream>

#include<iomanip>

#include<cmath>

#include "Functions.h"
//Header File that includes the Declarations of Required Functions
using std::cout;

using std::cin;

using std::endl;

using std::setw;

using std::left;

using std::right;

using std::setprecision;

using std::fixed;

int main()

{
    
const int table_width=14;

    float taxable_income;

    cout<<endl<<"Income?";

    cin>>taxable_income;

    if(cin.fail())

      {

	cout<<endl<<"PLEASE ENTER A CORRECT VALUE FOR INCOME\n";

	return 1;

      }

    if(taxable_income<=0) 
           //Error Checking

      {

	cout<<endl<<"INCOME SHOULD NOT BE A NEGATIVE VALUE OR ZERO\n";

	return 1;

      }
 
   cout<<"Exact tax";

    cout<<endl<<"Single:"<<setw(36)<<fixed<<setprecision(2)<<single(taxable_income);

    cout<<endl<<"Married filing jointly:"<<setw(20)<<married_Joint(taxable_income);

    cout<<endl<<"Married filing seperately:"<<setw(17)<<married_Seperate(taxable_income);
 
   cout<<endl<<"Head of household:"<<setw(25)<<head_Household(taxable_income);

    cout<<endl;

    cout<<endl<<setw(13)<<left<<"Income"<<"|"<<setw(28)<<right<<"Married"<<setw(14)<<"Married"<<setw(14)<<"Head";

    cout<<endl<<setw(13)<<left<<"Range"<<"|"<<setw(28)<<right<<"Filing"<<setw(14)<<"Filing"<<setw(14)<<"of";

    cout<<endl<<setw(14)<<"|"<<setw(14)<<right<<"Single"<<setw(14)<<"Jointly"<<setw(14)<<"Seperately"<<setw(14)<<"Household"<<endl;

    cout<<"----------------------------------------------------------------------"<<endl;
    double tab_low,tab_high;
    
tab_low=(floor(taxable_income/1000))*1000;//Calculating the lowest range value of the table

    tab_high=tab_low+1000; 
                   //since the difference should be 1000
    
double range_low,range_high;

    float range_avg;

    range_low=tab_low;

                                                /*Printing the table until the lowest range value is
                                                  less than the table highest range value  by calling
                                                  respective functions*/
    while(range_low<tab_high)
      {
	    range_high=range_low+50.00;       //Since each row should take range of 50
	    range_avg=(float)(range_low+range_high)/2;
	    cout<<setw(6)<<fixed<<setprecision(0)<<range_low<<"-"<<setw(6)<<right<<range_high<<"|"<<setw(table_width)<<round(single(range_avg));
	    cout<<setw(table_width)<<fixed<<setprecision(0)<<round(married_Joint(range_avg))<<setw(table_width)<<round(married_Seperate(range_avg));
	    cout<<setw(table_width)<<fixed<<setprecision(0)<<round(head_Household(range_avg))<<endl;
	    range_low=range_high;                   //give each row high value to low.so it starts from that value from next row.
      }
    return 0;
}
