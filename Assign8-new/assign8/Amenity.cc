#include "Amenity.h"

Amenity:: Amenity()
{
  jan_temp=0.0;
  jan_sunshine=0.0;
  avg_july_temp=0.0;
  avg_july_humidity=0.0;
  terrain=0.0;
  landform=0;
  ID=0;
  country_name="";
  state_abbr="";
  comp_amenity_value=0.0;
}
Amenity :: Amenity(int id,string abbr,string name,float temp,float sunshine,float jul_temp,float july_humidity,int landform_value,float terr)
{
    jan_temp=temp;
  jan_sunshine=sunshine;
  avg_july_temp=jul_temp;
  avg_july_humidity=july_humidity;
  terrain=terr;
  landform=landform_value;
  ID=id;
  country_name=name;
  state_abbr=abbr;
}
void Amenity:: set_Comp_Amenity_Value(float value)
{
  comp_amenity_value=value;
}
float Amenity:: get_Comp_Amenity_Value()const
{
  return comp_amenity_value;
}
string Amenity:: get_country_name()const
{
  return country_name;
}
string Amenity:: get_state_abbr()const
{
  return state_abbr;
}
float Amenity:: get_jan_temp()const
{
  return jan_temp;
}
float Amenity:: get_jan_sunshine()const
{
  return jan_sunshine;
}
float Amenity:: get_avg_july_temp()const
{
  return avg_july_temp;
}
float Amenity:: get_avg_july_humidity()const
{
  return avg_july_humidity;
}
float Amenity:: get_terrain()const
{
  return terrain;
}
int Amenity:: get_landform()const
{
  return landform;
}
int Amenity:: get_Id()const
{
  return ID;
}
bool compare_January_Temperature(const Amenity &ref1,const Amenity &ref2)
{
  if((ref1).get_jan_temp()>(ref2).get_jan_temp())
    {
      return true;
    }
  return false;
}
bool compare_January_Sunshine(const Amenity &ref1,const Amenity &ref2)
{
  if((ref1).get_jan_sunshine()>(ref2).get_jan_sunshine())
    {
      return true;
    }
  return false;
}
bool compare_July_Temperature(const Amenity &ref1,const Amenity &ref2)
{
  if((ref1).get_avg_july_temp()<(ref2).get_avg_july_temp())
    {
      return true;
    }
  return false;
}
bool compare_July_Humidity(const Amenity &ref1,const Amenity &ref2)
{
  if((ref1).get_avg_july_humidity()<(ref2).get_avg_july_humidity())
    {
      return true;
    }
  return false;
}
bool compare_Terrain(const Amenity &ref1,const Amenity &ref2)
{
  if((ref1).get_terrain()>(ref2).get_terrain())
    {
      return true;
    }
  return false;
}
bool compare_Landform(const Amenity &ref1,const Amenity &ref2)
{
  if((ref1).get_landform()>(ref2).get_landform())
    {
      return true;
    }
  return false;
}
//Functions that help to get vector of floats
void getall_jan_temp(vector<Amenity> &ref,vector<float> &v)
{
  //all_jan_temp.resize(3073);
  cout<<"\n size of Amenity  is "<<ref.size();
  for(auto i=ref.begin();i!=ref.end();++i)
    {
      v.push_back((*i).get_jan_temp());
    }
  cout<<"\n size of float vector is"<<v.size();
}
void getall_jan_sunshine(vector<Amenity> &ref,vector<float> &v)
{
  //all_jan_temp.resize(3073);
  // cout<<"\n size of Amenity  is "<<ref.size();
  for(auto i=ref.begin();i!=ref.end();++i)
    {
      v.push_back((*i).get_jan_sunshine());
    }
  cout<<"\n size of float vector is"<<v.size();
}
void getall_avg_july_temp(vector<Amenity> &ref,vector<float> &v)
{
  //all_jan_temp.resize(3073);
  cout<<"\n size of Amenity  is "<<ref.size();
  for(auto i=ref.begin();i!=ref.end();++i)
    {
      v.push_back((*i).get_avg_july_temp());
    }
  cout<<"\n size of float vector is"<<v.size();
}
void getall_avg_july_humidity(vector<Amenity> &ref,vector<float> &v)
{
  //all_jan_temp.resize(3073);
  cout<<"\n size of Amenity  is "<<ref.size();
  for(auto i=ref.begin();i!=ref.end();++i)
    {
      v.push_back((*i).get_avg_july_humidity());
    }
  cout<<"\n size of float vector is"<<v.size();
}
void getall_terrain(vector<Amenity> &ref,vector<float> &v)
{
  //all_jan_temp.resize(3073);
  cout<<"\n size of Amenity  is "<<ref.size();
  for(auto i=ref.begin();i!=ref.end();++i)
    {
      v.push_back((*i).get_terrain());
    }
  cout<<"\n size of float vector is"<<v.size();
}
void getall_landform(vector<Amenity> &ref,vector<float> &v)
{
  //all_jan_temp.resize(3073);
  cout<<"\n size of Amenity  is "<<ref.size();
  for(auto i=ref.begin();i!=ref.end();++i)
    {
      v.push_back((*i).get_landform());
    }
  cout<<"\n size of float vector is"<<v.size();
}
//Math Utility Functions

float calculate_Average(vector<float> &v)
{
  
  float sum;
  //cout<<"\n executing before for each";
  for_each( v.begin(),v.end(),[&sum](float x){sum=sum+x;});
  return (sum/v.size());
}
float calculate_StandardDeviation(vector<float> &v,float &avg)
{
  float sum_of_squares=0.0;
  /* for_each(v.begin(),v.end(),[&sum_of_squares,&avg](int x){sum_of_squares=sum_of_squares+((x-avg)*(x-avg));});*/
  for_each(v.begin(),v.end(),[&sum_of_squares,&avg](int x){sum_of_squares=sum_of_squares+pow((x-avg),2);});
  //float variance=sum_of_squares/(v.size()-1);
  //   return pow(variance,0.5);
  return pow((sum_of_squares/(v.size()-1)),0.5);
}

