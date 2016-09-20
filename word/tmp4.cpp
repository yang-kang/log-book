#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

template<class Y>
//struct head_link
Y
{
	char name[10];
	int age;
	Y *next;
};
//typedef struct head_link L;
template<class Y>
Y *paixu(Y *head,Y *pnew)
{
	Y *p1;
	Y *p2;
	p1=p2=head;
	while(p1!=NULL&&strcmp(pnew->name,p1->name)<=0)
	{
		p2=p1;
		p1=p1->next;
	}
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
template<class Y>
Y *delete_link(Y *head,char* str)
{
	Y *p1=NULL;
	Y *p2=NULL;
	p1=p2=head;

	while(p1!=NULL&&strcmp(p1->name,str)!=0)
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
template<class Y>
Y *search_link(Y *head,char *str)
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
template<class Y>
void put_link(Y *head)
{
	Y *p=head;
	while(p!=NULL)
	{
		cout<<"姓名:"<<p->name<<"年龄："<<p->age<<endl;
		p=p->next;
	}
}
int main()
{/*
	struct head_link* pnew=NULL;
	struct head_link* head=NULL;
	pnew=(struct head_link*)malloc(sizeof(struct head_link));
	strcpy(pnew->name,"刘备");
	pnew->age=100;
	head=paixu(head,pnew);
	put_link(head);*/
	return 0;
}
