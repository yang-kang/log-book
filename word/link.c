#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  strlen(char *str) 求str长度
  strcat(char *str1,char *str2)  将str2连接到str1后面
  strcpy(char *str1,char *str2)  将str2拷贝到str1位置
  strcmp(char *str1,char *str2)  比较str1和str2内容，返回值：0,相等。负数，str1<str2, 正数，str1>str2
*/

struct employee
{
  char name[10];
  char sex[4];
  unsigned short age;
  struct employee *next;
};
typedef struct employee EM;

void putEM(const EM *p)
{
  printf("姓名:%s\t性别:%s\t年龄:%hu\n",p->name,p->sex,p->age);
}
EM *getEM()
{
  EM *p=malloc(sizeof(EM));
  printf("请输入姓名:");
  scanf("%s",p->name);
  printf("请输入性别:");
  scanf("%s",p->sex);
  printf("请输入年龄:");
  scanf("%hu",&(p->age));
  p->next=NULL;
  return p;
}
void print_link(const EM *head)
{
  while(head!=NULL)
  {
    putEM(head);
    head=head->next;  
  }
}

//插入尾部
EM *insert_link1(EM *head,EM *pnew)
{
  EM *p=head;
  //找位置
  while(p!=NULL&&p->next!=NULL)
  {
    p=p->next;  
  }
  //插入  
  if(head==NULL)
  {
    head=pnew;  
  }
  else
  {
    p->next=pnew;  
  }
  return head;
}

//插入头部
EM *insert_link2(EM *head,EM *pnew)
{
  pnew->next=head;
  head=pnew;
  return head;
}

//按顺序插
EM *insert_link3(EM *head,EM *pnew)
{
  EM *p1,*p2;
  
  //找位置
  p1=p2=head;
  while(p1!=NULL&&strcmp(p1->name,pnew->name)<0)
  {
    p2=p1;
    p1=p1->next;  
  }
  //插入  
  if(p1==p2)
  {
    pnew->next=head;
    head=pnew;  
  }
  else
  {
    pnew->next=p1;
    p2->next=pnew;
  }
  return head;
}

EM *search_link(EM *head,char *str)
{
    while(head!=NULL)
    {
        if(strcmp(head->name,str)==0)
        {
          return head;  
        }
        head=head->next;
    }
    return NULL;
}
EM *delete_node(EM *head,EM *pd)
{
  EM *p1,*p2;
  
  p1=p2=head;
  while(p1!=NULL&&strcmp(p1->name,pd->name)!=0)
  {
    p2=p1;
    p1=p1->next;  
  }
  if(p1!=NULL)
  {
    if(p1==p2)
    {
      head=p1->next;  
    }
    else
    {
      p2->next=p1->next;  
    }
    free(p1);
  }
  return head;
}
int main()
{
  EM *head=NULL;
  EM *pnew=NULL;
  int sel;
  char msg[10]="";
  while(1)
  {
    printf("是否继续:");
    scanf("%d",&sel);
    if(sel==0)
    {
      break;  
    }
    pnew=getEM();
    head=insert_link3(head,pnew);
  }
  print_link(head);
  printf("请输入你要查找的节点信息:");
  scanf("%s",msg);
  pnew=search_link(head,msg);
  head=delete_node(head,pnew);
  print_link(head);
  return 0;
}
