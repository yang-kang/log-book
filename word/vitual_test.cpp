#include <iostream>
#include "mystring.h"
using namespace std;
class Employee
{
  protected:
    MyString name;
    float salary;
  public:
    Employee(const char *s,float f)
    {
      name=s;  
      salary=f;
    }
    void set_name(const char *n)
    {
      strcpy(name,n);  
    }
    const char *get_name()
    {
      return name;  
    }
    virtual void pay()
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
    float countSalary()
    {
      return work_age*100+salary;  
    }
    void pay()
    {
      cout<<"输入工龄:";
      cin>>work_age;
      cout<<"行政人员:"<<get_name()<<"的薪水是"<<countSalary()<<endl;  
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
    float countSalary()
    {
      return ach*0.2+salary;  
    }  
    void pay()
    {
      cout<<"销售人员"<<name<<"的薪水是"<<countSalary()<<endl;  
    }
};

struct node
{
  Employee *info;
  struct node *next;  
};
struct node *insert_link(struct node *head,struct node *pnew)
{
  pnew->next=head;
  head=pnew;
  return head; 
}

void put_link(struct node *head)
{
  while(head!=NULL)
  {
    (head->info)->pay();
    head=head->next;  
  }
}

int main()
{
  int sel=0;
  int sel2=0;
  char name[20];
  float b_s;
  struct node *pnew=NULL;
  struct node *head=NULL;
  while(1)
  {
    cout<<"选择你要进行的操作:\n1.录入员工信息;2.计算员工工资;3.退出系统\n";
    cin>>sel;
    switch(sel)
    {
      case 1:
        // 增加员工
        pnew=new struct node;
        cout<<"请输入员工姓名:\n";
        cin>>name;
        cout<<"请选择员工类型:1.行政;2.销售\n";
        cin>>sel2;
        switch(sel2)
        {
          case 1:
              (pnew->info)=new Officer(name,2000,0);
              pnew->next=NULL;
              break;
          case 2:
              (pnew->info)=new Saler(name,2000,0);
              pnew->next=NULL;
              break;
          default:
              pnew->info=new Employee("无名",0);
              break;
        }
        head=insert_link(head,pnew);
        break;
      case 2:
        //输出全天员工pay()函数.
        put_link(head);
        break;
      case 3:
        return 0;
      default:
        break;  
    }
  }
  return 0;
}
