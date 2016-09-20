#include <iostream>
#include "mystring.h"
using namespace std;
class Employee
{
  private:
    MyString name;
  protected:
    float salary;
  public:
    Employee(const char *s,float f)
    {
      name=s;  
      salary=f;
    }
    void pay()
    {
      cout<<"你的薪水是"<<salary<<endl;  
    }
};

class Officer:public Employee
{
  private:
    int work_age;//工龄
  public:
    Officer(const char *name,float f,int year):Employee(name,f)
    {
      work_age=year;  
    }
    void countSalary()
    {
      salary=work_age*100+salary;  
    }
};

class Saler:public Employee
{
  private:
    int ach;//业绩
  public:
    Saler(const char *name,float f,int _ach):Employee(name,f)
    {
      ach=_ach;  
    }
    void countSalary()
    {
      salary=ach*0.2+salary;  
    }  
};

int main()
{
  Officer e1("张三",2000,2);
  Saler e2("李四",1000,50000);
  e1.countSalary();
  e2.countSalary();
  e1.pay();
  e2.pay();
  return 0;
}
