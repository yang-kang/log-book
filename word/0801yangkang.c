#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

struct head_link
{
	char name[10];
	char sex[4];
	unsigned short age;
	struct head_link *next; 
};
void scanf_link(struct head_link *pnew)
{
	printf("请输入姓名：");
	scanf("%s",pnew->name);
	printf("请输入性别：");
	scanf("%s",pnew->sex);
	printf("请输入年龄：");
	scanf("%d",&(pnew->age));
}
void printf_link(struct head_link *head)
{
	struct head_link *p1=head;
	while(p1!=NULL)
	{
		printf("姓名：%s\t性别：%s\t年龄：%u\n",p1->name,p1->sex,p1->age);
		p1=p1->next;
	}
}
struct head_link* add_link(struct head_link *pnew,struct head_link *head)
{
	
	struct head_link *p=NULL;
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
struct head_link* delete_link(struct head_link *head)
{
	struct head_link *p=NULL;
	p=head->next;//删除第二个节点
	if(p!=NULL&&p->next!=NULL)
	{
		head->next=p->next;
	}
	if(p->next==NULL);
	{head->next=NULL;}
	return head;
}
int main()
{
	struct head_link *pnew=NULL;
	struct head_link *head=NULL;
	int sel=0;

	while(1)
	{
		printf("是否要添加节点：");
		scanf("%d",&sel);
		if(sel==0)
		{
			break;
		}
		pnew=malloc(sizeof(struct head_link));
		scanf_link(pnew);
		head=add_link(pnew,head);
		/*p=head;
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
		pnew->next=NULL;*/
	}
	printf_link(head);
	printf("删除第二个节点：\n");
	printf_link(delete_link(head));
	return 0;
}

