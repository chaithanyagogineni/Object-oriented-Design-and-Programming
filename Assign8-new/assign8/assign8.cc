#include "Amenity.h"
#include "assign8.h"
int main(int argc,char *argv[])
{
  if(argc!=2)
    {
      cerr<<"\n USAGE:"<<argv[0]<<" Input File";
      return -1;
    }
   vector<Amenity> country_amenities;
   /*vector<float> all_jan_temp;
    vector<float> all_jan_sunshine;
      vector<float> all_july_temp;
        vector<float> all_july_humidity;
	  vector<float> all_terrain;
	    vector<float> all_landform;
  */    
  int result=input(argv[1],country_amenities);
  if(result!=0)
    {
      return -1;
    }
  /*//getting the vector of floats for January temperature
  getall_jan_temp(country_amenities,all_jan_temp);
  getall_jan_sunshine(country_amenities,all_jan_sunshine);
  getall_avg_july_temp(country_amenities,all_july_temp);
  getall_avg_july_humidity(country_amenities,all_july_humidity);
  getall_terrain(country_amenities,all_terrain);
  getall_landform(country_amenities,all_landform);
  //getting the vector of floats for January sunshine
  float avg_all_jan_temp=calculate_Average(all_jan_temp);
  cout<<"\n january Temperatiure average obtained is "<<avg_all_jan_temp;

  float avg_all_jan_sunshine=calculate_Average(all_jan_sunshine);
  cout<<"\n january Sunshine average obtained is "<<avg_all_jan_sunshine;

  float avg_all_july_temp=calculate_Average(all_july_temp);
  cout<<"\n july Temperatiure average obtained is "<<avg_all_july_temp;

  float avg_all_july_humidity=calculate_Average(all_july_humidity);
  cout<<"\n july Humidity  average obtained is "<<avg_all_july_humidity;
  
  float avg_all_landform=calculate_Average(all_landform);
  cout<<"\n Landform  average obtained is "<<avg_all_landform;

  float avg_all_terrain=calculate_Average(all_terrain);
  cout<<"\n Terrain  average obtained is "<<avg_all_terrain;

  float std_all_jan_temp=calculate_StandardDeviation(all_jan_temp,avg_all_jan_temp);
  cout<<"\n january Temperatiure standard deviation obtained is "<<std_all_jan_temp;

  float std_all_jan_sunshine=calculate_StandardDeviation(all_jan_sunshine,avg_all_jan_sunshine);
  cout<<"\n january Sunshine standard obtained is "<<std_all_jan_sunshine;

  float std_all_july_temp=calculate_StandardDeviation(all_july_temp,avg_all_july_temp);
  cout<<"\n july Temperatiure standard obtained is "<<std_all_july_temp;

  float std_all_july_humidity=calculate_StandardDeviation(all_july_humidity,avg_all_july_humidity);
  cout<<"\n july Humidity  standard obtained is "<<std_all_july_humidity;
  
  float std_all_landform=calculate_StandardDeviation(all_landform,avg_all_landform);
  cout<<"\n Landform  standard obtained is "<<std_all_landform;

  float std_all_terrain=calculate_StandardDeviation(all_terrain,avg_all_terrain);
  cout<<"\n Terrain  standard obtained is "<<std_all_terrain;
  */
  Composite_amenity(country_amenities);
  AmenityHelper obj;
     //Generating Report based on January Temperature
  cout<<"\nRanking by January Temperature\n";
  cout<<"============================================================\n";
  obj.set_Id(1);
  stable_sort(country_amenities.begin(),country_amenities.end(),compare_January_Temperature);
  print_top_bottom_n(country_amenities,12,obj);
  //Generating Reports based  on January Sunshine
  cout<<"\nRanking by January Sunshine\n";
  cout<<"============================================================\n";
    obj.set_Id(2);
  stable_sort(country_amenities.begin(),country_amenities.end(),compare_January_Sunshine);
  print_top_bottom_n(country_amenities,12,obj);
  //Generating Reports based on Average July Temperature
  cout<<"\nRanking by Average July Temperature\n";
  cout<<"============================================================\n";
  obj.set_Id(3);
  stable_sort(country_amenities.begin(),country_amenities.end(),compare_July_Temperature);
  print_top_bottom_n(country_amenities,12,obj);

  //Generating Reports based on Average July Humidity
  cout<<"\nRanking by Average July  Humidity\n";
  cout<<"============================================================\n";
  obj.set_Id(4);
  stable_sort(country_amenities.begin(),country_amenities.end(),compare_July_Humidity);
  print_top_bottom_n(country_amenities,12,obj);

  //Generating Reports based on Landform
  cout<<"\nRanking by Landform\n";
  cout<<"============================================================\n";
  obj.set_Id(5);
  stable_sort(country_amenities.begin(),country_amenities.end(),compare_Landform);
  print_top_bottom_n(country_amenities,12,obj);
  
  //Generatin Reports based on Terrain
  cout<<"\nRanking by Water Area\n";
  cout<<"============================================================\n";
  obj.set_Id(6);
  stable_sort(country_amenities.begin(),country_amenities.end(),compare_Terrain);
  print_top_bottom_n(country_amenities,12,obj);

  
    //Generatin Reports based on Composite Amenity Value
  cout<<"\nComposite Ranking \n";
  cout<<"============================================================\n";
  obj.set_Id(7);
  
  stable_sort(country_amenities.begin(),country_amenities.end(),obj);
  print_top_bottom_n(country_amenities,10,obj);
  
  return 0;
}
