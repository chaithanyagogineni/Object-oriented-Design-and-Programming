/*This assignment-6 is done by chaithanya krishna G.
ZID:Z1815642
CSCI-689
sec-0001
T.A: Nithin Devang
*/
//Including the header file for main program (assign6.cc)
#include "assign6.h"

/*Main function takes 2 arguments.
1.integer that specifies number of arguments
2.pointer to array of characters
*/

int main(int argc,char *argv[])
{
  /*Checking the correct number of arguments*/
  if(argc!=2)
    {
      cerr<<"\nUsage: "<<argv[0]<<" [Data file] \n";
      return -1;
    }
    vector<Person> p;
    ifstream inp;
    inp.open(argv[1]);
    //checking whether the file  is opened properly
    if(!inp.is_open())
      {
      cerr<<"\n unable to open the file .Please check whether the file exists\n";
      return -1;
      }
    string data[20];
    char ch;
    int root=0;
    //store the data of each person in an array and push it into vector until end of file
    while(!inp.eof())
      {
	for(int i=0;i<17;i++)
	  {
	    std::getline(inp,data[i]); //to input each line into  STRING
	  }		
	//Initialising the values of Names,birth Date,birth Place,death date,death place  and root values of father,mother,child with parameterized constructors
      Name a(data[0]);
      Name b(data[1]);
      Date c(data[2],data[3],data[4]);
      Place d(data[5],data[6],data[7]);
      Date e(data[8],data[9],data[10]);
      Place f(data[11],data[12],data[13]);
      int g=stoi(data[14]);//converting string into integer
      int h=stoi(data[15]);
      int i=stoi(data[16]);
      //Initailsing each person with objects initialisedd above
      	Person obj(a,b,c,d,e,f,g,h,i);
	//pushing each person into vector
      	p.push_back(obj);    
      
    }
    inp.close();//Closing the file stream.
    
   
    //perform this,until the user choose  to quit
    do
    {
      //creating an instance of textCanvas class
    textCanvas obj;
       //calling the print_pedigree function.
      print_pedigree(obj,p,root);
      cout<<"\nMove to F)ather, M)other ,C)hild or Q)uit?";
      cin>>ch;
      switch(ch)
	{
	  //If the choice is Father
	case 'F':
	  if(p[root].get_father()!=-1)
	    root=p[root].get_father();
	  break;
	case 'f':
	  if(p[root].get_father()!=-1)
	    root=p[root].get_father();
	  break;
	  //If the choice is Mother
	case 'M':
	  if(p[root].get_mother()!=-1)
	    root=p[root].get_mother();
	  break;
	case 'm':
	  if(p[root].get_mother()!=-1)
	    root=p[root].get_mother();
	  break;
	  //If the choice is Child
	case 'C':
	  if(p[root].get_child()!=-1)
	    root=p[root].get_child();
	  break;
	case 'c':
	  if(p[root].get_child()!=-1)
	    root=p[root].get_child();
	  break;
	case 'q':exit(1);break;
	case 'Q':exit(1);break;
	  //If nothing matches the choice above
	default:cout<<"\n please select proper value\n";
	  break;
	}
	}while(ch!='q'||ch!='Q');
  return 0;  
}

/*This function takes 3 arguments.
1.reference to textCanvas Class.
2.reference to vector of persons.
3.integer specifying the root.
 */
void print_pedigree(textCanvas& tc, const vector<Person> & person, int root)
{
  tc.clear();
  // Print tree diagram
  
  const int boxwidth = CWIDTH / 3;     // Three generations
  const int boxheight = CHEIGHT / 4;   // Four ancestors in third generation

  const int root_x = 0;
  const int root_y = int(1.5 * boxheight);

  const int father_x = boxwidth;
  const int father_y = int(0.5 * boxheight);

  const int mother_x = boxwidth;
  const int mother_y = int(2.5 * boxheight);

  const int pgf_x = 2 * boxwidth;  // Paternal grandfather
  const int pgf_y = 0;

  const int pgm_x = 2 * boxwidth;  // Paternal grandmother
  const int pgm_y = boxheight;

  const int mgf_x = 2 * boxwidth;  // Maternal grandfather
  const int mgf_y = 2 * boxheight;

  const int mgm_x = 2 * boxwidth;  // Maternal grandmother
  const int mgm_y = 3 * boxheight;


  // Line for root
  tc.print_horizontal_line(root_x, root_y, boxwidth);

  // Horizontal line for father
  tc.print_horizontal_line(father_x, father_y, boxwidth);

  // Horizontal line for mother
  tc.print_horizontal_line(mother_x, mother_y, boxwidth);

  // Horizontal lines for grandparents
  tc.print_horizontal_line(pgf_x, pgf_y, boxwidth);
  tc.print_horizontal_line(pgm_x, pgm_y, boxwidth);
  tc.print_horizontal_line(mgf_x, mgf_y, boxwidth);
  tc.print_horizontal_line(mgm_x, mgm_y, boxwidth);

  // Vertical lines
  tc.print_vertical_line(father_x, father_y, 2 * boxheight);
  tc.print_vertical_line(pgf_x, pgf_y, boxheight);
  tc.print_vertical_line(mgf_x, mgf_y, boxheight);

  // Print the pedigree
  int person_id = root;
  tc.set_box(root_x, root_y, boxwidth, boxheight);
  
  person[person_id].print(tc);
  
  // Print father's line
  if(person[person_id].get_father() != -1){
    person_id = person[root].get_father();
    tc.set_box(father_x, father_y, boxwidth, boxheight);
    person[person_id].print(tc);

  if(person[person_id].get_father() != -1){
    tc.set_box(pgf_x, pgf_y, boxwidth, boxheight);
    person[person[person_id].get_father()].print(tc);
  }
  if(person[person_id].get_mother() != -1){
    tc.set_box(pgm_x, pgm_y, boxwidth, boxheight);
    person[person[person_id].get_mother()].print(tc);
  }
}

  // Print mother's line
  if(person[root].get_mother() != -1){
    person_id = person[root].get_mother();
    tc.set_box(mother_x, mother_y, boxwidth, boxheight);
    person[person_id].print(tc);

    if(person[person_id].get_father() != -1){
      tc.set_box(mgf_x, mgf_y, boxwidth, boxheight);
      person[person[person_id].get_father()].print(tc);
    }
    if(person[person_id].get_mother() != -1){
      tc.set_box(mgm_x, mgm_y, boxwidth, boxheight);
      person[person[person_id].get_mother()].print(tc);
    }
  }
  
            tc.print();
  
  }
