#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct link
{
	char name[10];
	char sex[4];
	unsigned short age;
	struct link *next;
};
void scanf_link(struct link* pnew)
{
	printf("请输入姓名:");
	scanf("%s",pnew->name);
	printf("请输入性别：");
	scanf("%s",pnew->sex);
	printf("请输入年龄：");
	scanf("%hu",&(pnew->age));
}
struct link* charu(struct link *pnew,struct link *head)
{
	struct link *p=NULL;
	p=head;
	while(head!=NULL&&p->next!=NULL)
	{
		p=p->next;
	}
	if(head==NULL)
	{
		head=pnew;
	}
	else
	{
		p->next=pnew;
	}
	pnew->next=NULL;
	return head;
}
void printf_link(struct link *head)
{
	struct link *p=head;
	while(p!=NULL)
	{
		printf("姓名：%s\t性别：%s\t年龄：%hu\n",p->name,p->sex,p->age);
		p=p->next;
	}
}
struct link* delete_link(struct link* head,char *str)
{
	struct link *p1=NULL;
	struct link *p2=NULL;
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
int main()
{
	struct link *head=NULL;
	struct link *pnew=NULL;
	int sel=0;
	char a[10];
	while(1)
	{
		printf("是否加入节点：");
		scanf("%d",&sel);
		if(sel==0)
		{
			break;
		}
		pnew=malloc(sizeof(struct link));
		scanf_link(pnew);
		head=charu(pnew,head);
	} 
	printf_link(head);
	printf("请输入要删除的节点姓名：");
	scanf("%s",a);
	printf_link(delete_link(head,a));
	return 0;
}
