#include <iostream>
#include <cstring>
#include "mystring.h"
using namespace std;

MyString::MyString()//无参构造
{
  data=new char[1];
  data[0]='\0';
  len=0;  
}
MyString::MyString(const char *str)
{
  len=strlen(str);
  data=new char[len+1];
  strcpy(data,str);
}
MyString::MyString(const MyString &s)
{
  len=s.len;
  data=new char[len+1];
  strcpy(data,s.data);  
}
MyString::~MyString()
{
  delete [] data;  
}
istream &operator>>(istream &in,MyString &s)
{
  in>>s.data;
  return in;  
}
ostream &operator<<(ostream &out,MyString &s)
{
  out<<s.data;
  return out;  
}

MyString &MyString::operator=(const MyString &s)
{
  delete [] data;
  len=s.len;
  data=new char [len+1];
  strcpy(data,s.data);
  return *this; 
}
MyString MyString::operator+(const MyString &s)
{
  MyString snew;
  snew.len=len+s.len;
  delete [] snew.data;
  snew.data=new char[snew.len+1];
  strcpy(snew.data,data);
  strcat(snew.data,s.data);
  return snew;
}
int MyString::operator==(const MyString &s)
{
  if(len==s.len&&(strcmp(data,s.data)==0))
  {
    return 0;  
  }
  else
  {
    return 1;  
  }
}
int MyString::operator>(const MyString &s)
{
  if(strcmp(data,s.data)>0)
  {
    return 0;  
  }
  else
  {
    return 1;  
  }
}
int MyString::operator<(const MyString &s)
{
  if(strcmp(data,s.data)<0)
  {
    return 0;  
  }
  else
  {
    return 1;  
  }
}
int MyString::operator>=(const MyString &s)
{
  if(strcmp(data,s.data)>=0)
  {
    return 0;  
  }
  else
  {
    return 1;  
  }
}
int MyString::operator<=(const MyString &s)
{
  if(strcmp(data,s.data)<=0)
  {
    return 0;  
  }
  else
  {
    return 1;  
  }
}
int MyString::operator!=(const MyString &s)
{  
  if(strcmp(data,s.data)!=0)
  {
    return 0;  
  }
  else
  {
    return 1;  
  }
}
