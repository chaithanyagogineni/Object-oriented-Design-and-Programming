/*  This function takes one parameter income 
    as input and returns the tax to be paid 
    if the payee is filing single.
    @param 1: float
    @return type:float
*/
float single(float a)
{
    float res;
    if(a>0&&a<=9275)
      res=(a*10)/100;
    else if(a>9275&&a<=37650)
      res=927.50+(a-9275)*15/100;
    else if(a>37650&&a<=91150)
      res=5183.75+(a-37650)*25/100;
    else if(a>91150&&a<=190150)
      res=18558.75+(a-91150)*28/100;
    else if(a>190150&&a<=413350)
      res=46278.75+(a-190150)*33/100;
    else if(a>413350&&a<=415050)
      res=119934.75+(a-413350)*35/100;
    else if(a>415050)
      res=120529.75+(a-415050)*39.6/100;
    return res;
}
/* This function takes one parameter income 
   as input and returns the tax to be paid 
   if the payee is Married and filing Jointly.
   @param 1: float
   return type:float
*/
float married_Joint(float a)
{
    float res;
    if(a>0&&a<=18550)
      res=(a*10)/100;
    else if(a>18550&&a<=75300)
      res=1855.00+(a-18550)*15/100;
    else if(a>75300&&a<=151900)
      res=10367.50+(a-75300)*25/100;
    else if(a>151900&&a<=231450)
      res=29517.50+(a-151900)*28/100;
    else if(a>231450&&a<=413350)
      res=51791.50+(a-231450)*33/100;
    else if(a>413350&&a<=466950)
      res=111818.50+(a-413350)*35/100;
    else if(a>466950)
      res=130578.50+(a-466950)*39.6/100;
    return res;
}
/* This function takes one parameter income 
   as input and returns the tax to be paid 
   if the payee is Married and filing Seperately.
   @param 1: float
   return type:float
*/
float married_Seperate(float a)
{
    float res;
    if(a>0&&a<=9275)
      res=(a*10)/100;
    else if(a>9275&&a<=37650)
      res=927.50+(a-9275)*15/100;
    else if(a>37650&&a<=75950)
      res=5183.75+(a-37650)*25/100;
    else if(a>75950&&a<=115725)
      res=14758.75+(a-75950)*28/100;
    else if(a>115725&&a<=206675)
      res=25895.75+(a-115725)*33/100;
    else if(a>206675&&a<=233475)
      res=55909.25+(a-206675)*35/100;
    else if(a>233475)
      res=65289.25+(a-233475)*39.6/100;
    return res;
}
/* This function takes one parameter income 
   as input and returns the tax to be paid 
   if the payee is Head of Household.
   @param 1 : float
   return type:float
*/
float head_Household(float a)
{
    float res;
    if(a>0&&a<=13250)
      res=(a*10)/100;
    else if(a>13250&&a<=50400)
      res=1325.00+(a-13250)*15/100;
    else if(a>50400&&a<=130150)
      res=6897.50+(a-50400)*25/100;
    else if(a>130150&&a<=210800)
      res=26835.00+(a-130150)*28/100;
    else if(a>210800&&a<=413350)
      res=49417.00+(a-210800)*33/100;
    else if(a>413350&&a<=441000)
      res=116258.50+(a-413350)*35/100;
    else if(a>441000)
      res=125936.00+(a-441000)*39.6/100;
    return res;
}

