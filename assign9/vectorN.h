
#ifndef VECTORN_H
#define VECTORN_H
#include<iostream>
#include<vector>
#include<ostream>
using std::ostream;
using std::cout;
using std::vector;
template<class T>
class VectorN
{
  //Private variables
int id;
T *data;
public:
//Default constructor that takes no args and returns nothing
VectorN();
//Parameterized constructor that takes 1 arg of integer andreturns nothing
VectorN(int n);
//paramtereized constructor that takes 2 arguments and returns nothing
VectorN(const T arr[],int size);
//Destructor that takes no arguments and returns nothing
~VectorN();
//Copy constructor that takes a reference to vectorN class and returns nothing
VectorN(const VectorN<T> & ref);
//Assignment operator overloading that takes a reference to vectorN class and returns a reference to vectorN class
VectorN<T>& operator =(const VectorN<T> &ref);
//clear method that takes no arguements and returns nothing
void clear();
//size method that takes no arguments and returns an integer
int size()const;
//overloading the subscript operator for reading
T operator [](int var)const;
//overloading the subscript operator for writing
T& operator [](int var);
//overloading comparison operator that takes reference to vectorN class and returns boolea
bool operator ==(const VectorN<T> &ref)const;
//overloading the addition operator that takes a reference to vector class
VectorN<T> operator +(const VectorN<T> &ref1)const;
//overloading the output stream operator.since it is a friend function,not a methos of class,used seperate template
 template<class R>
friend ostream& operator <<(ostream &ref1,const VectorN<R> &ref2);
};
//implementing the constructor of vectorN template class
template<class T>
VectorN<T> :: VectorN()
{
  id=0;
  data=new T[id];
}
//implementing the parameterized constructor of vectorN class that takes single parameter set the size 
template<class T>
VectorN<T> :: VectorN(int n)
{
  id=n;
  data=new T[id];
  for(int i=0;i<id;i++)
    {
      data[i]=0;
    }
}
//implementing the paramterized constructor of vectorN class that takes an array and size and copy the array to member variable
template<class T>
VectorN<T> :: VectorN(const T ref[],int num)
{
  id=num;
  data=new T[num];
  for(int i=0;i<id;i++)
    {
      data[i]=ref[i];
    }
}
//implementing the destructor of vectorN class
template<class T>
VectorN<T> :: ~VectorN()
{
  delete[] data;
}
//implementing the copy constructor of the vectorN class takes a reference to vectorN class 
template<class T>
VectorN<T> :: VectorN(const VectorN<T> &ref)
{
  (*this).id=ref.id;
  (*this).data=new T[ref.id];
  for(int i=0;i<(*this).id;i++)
    {
      (*this).data[i]=ref.data[i];
    }
}
//implementing the output stream operator that takes output stream reference and a reference to vectorN and  print the member variables of class.
//returns a refrence to output stream
template<class R>
ostream& operator <<(ostream &ref1,const VectorN<R> &ref2)
{
  cout<<"[";
  for(int i=0;i<ref2.id;i++)
    {
      ref1<<ref2.data[i];
      if(i!=(ref2.id)-1)
	cout<<",";
    }
  cout<<"]";
  return ref1;  
}
//implementing the clear method of the vectorN class takes no arguments and returns nothing
template<class T>
void VectorN<T>:: clear()
{
  id=0;
  data=new T[id];
  //delete []data;  
}
//implementing the size method of vectorN class takes no args and returns an int representing the size
template<class T>
int VectorN<T>:: size()const
{
  return id;
}
//overlaoding the subscripting operator for reading.this acts as accessor.returns template variable
template<class T>
T VectorN<T> :: operator [](int var)const
{
  return (*this).data[var]; 
}
//overloading the subscripting operator for writing.This returns a reference of template type
template<class T>
T& VectorN<T> :: operator [](int var)
{
  return (*this).data[var];
}
//overlaoding the assignment operator that takes a const reference to vectorN class .returns a reference to vectorN class
template<class T>
VectorN<T>& VectorN<T> :: operator =(const VectorN<T> &ref)
{
  if(this==&ref)
    {
      return *this;
    }
  else
    {
  delete [] (*this).data;
  (*this).id=ref.id;
  (*this).data=new T[ref.id];
  for(int i=0;i<ref.id;i++)
    {
      (*this).data[i]=ref.data[i];
    }
  return *this;
}
}
//overloading the comparison operator .take sa constant reference to vectorN class and returns boolean
template<class T>
bool VectorN<T> :: operator ==(const VectorN<T> &ref)const
  {
    int flag=0;
    if(this==&ref)
      return true;
    else
      {
	if((*this).id==(ref).id)
	  {
	    for(int i=0;i<ref.id;i++)
	     {
	       if((*this).data[i]==ref.data[i])
		 {
		    flag=1;
		 }
	       else
		 {
		   flag=0;
		   break;
		 }
	     }
         }
      }
    if(flag!=1)
      return false;
    return true;
  }
//overlaoding the addition operator for the vectorN class.takes a const reference to vectorN class.
template<class T>
VectorN<T> VectorN<T> :: operator +(const VectorN<T> &ref)const
{
  int size=((*this).id>ref.id)?(ref.id):(*this).id;
  T *dat=new T[size]; 
  for(int i=0;i<size;i++)
    {
      dat[i]=(*this).data[i]+ref.data[i];
    }
  cout<<"\n size is "<<size;
  VectorN<T> obj(dat,size);
  return obj;
  
}
#endif
//end of  header file VECTORN_H
