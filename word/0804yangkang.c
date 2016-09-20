#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp=NULL;

typedef struct head_link
{
	char name[10];
	char sex[4];
	unsigned short age;
	struct head_link *next;
}EM;

EM *delete_link(EM *head,char* str)
{
	EM *p1=NULL;
	EM *p2=NULL;
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
EM *scanf_link()
{
	EM* p=NULL;
	p=malloc(sizeof(EM));
	fscanf(fp,"%s",p->name);
	fscanf(fp,"%s",p->sex);
	fscanf(fp,"%hu",&(p->age));
	p->next=NULL;
	return p;

}
EM *scanf_link1()
{
  EM *p1=malloc(sizeof(EM));
  printf("请输入姓名:");
  scanf("%s",p1->name);
  printf("请输入性别:");
  scanf("%s",p1->sex);
  printf("请输入年龄:");
  scanf("%hu",&(p1->age));
  p1->next=NULL;
  return p1;
}
void put_p(EM *p)
{
	printf("姓名:%s\t性别:%s\t年龄:%d\n",p->name,p->sex,p->age);
}
void putting(struct head_link *head)
{
	struct head_link *p=head;
	while(p!=NULL)
	{
		put_p(p);
		p=p->next;
	}
}
struct head_link* paixiu(EM *head,EM *pnew)
{
	struct head_link *p1;
	struct head_link *p2;
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
int main()
{
	EM *head=NULL;
	EM *pnew=NULL;
	int sel=0,i=0;
	int n=0,m=0;
	char arr[10];
	FILE *fp1=NULL;
	int flag=0;
	FILE *fp2=NULL;
	char arr1[10];
	char arr2[10];
        int z=0;
	fp=fopen("date","r");
	fscanf(fp,"%d",&n);
	for(sel=1;sel<=n;sel++)
	{
		pnew=scanf_link();
		head=paixiu(head,pnew);
	}
	fclose(fp);

	fp2=fopen("date1","r");
	fscanf(fp2,"%s",arr1);
	fclose(fp2);
	while(1)
	{
		printf("请输入密码：");
        	scanf("%s",arr2);
		if(strcmp(arr1,arr2)==0)
		{
			break;
		}
		else
		{
			printf("输入错误！\n重新输入（1）退出（0）\n请选择是否继续：");
                        scanf("%d",&i);
			if(i==0)
			{
				return 0;
			}
		}
	}
	while(1)
	{
		printf("\t\t\t显示菜单\n");
		printf("1.增加\t2.查找\t3.删除\t4.查看全部\t5.退出保存\n");
		printf("请用户选择：");
		scanf("%d",&m);
		switch(m)
		{
		case 1:pnew=scanf_link1();
			head=paixiu(head,pnew);n++;break;
		case 2:printf("请输入要查找的节点：");
			scanf("%s",arr);
			head=search_link(head,arr); 
			put_p(head);break;
		case 3:printf("请输入要删除的节点：");
			scanf("%s",arr);
			head=delete_link(head,arr);
			putting(head);n--;break;
		case 4:putting(head);break;
		case 5:fp1=fopen("date","w");
			fprintf(fp1,"%d\n",n);
  			while(head!=NULL)
			{
				fprintf(fp1,"%s\t",head->name);
				fprintf(fp1,"%s\t",head->sex);
 				fprintf(fp1,"%hu\n",head->age);
				head=head->next;
			}
			fclose(fp1);flag=1;break;
			default :printf("非法输入！");break;
		}
		if(flag==1)
		{
			break;
		}
		
	}
	return 0;
}
