#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ie_link
{
	char tag[9];
	char length[5];
	char *value;
	struct ie_link *next;
}IE;
int length_num(char ch,int num)
{
	if(ch>='0'&&ch<='9')
	{
		num+=ch-'0';
	}
	else
	{
		num+=ch-'W';
	}
	return num;
}
void printf_link(IE *head)
{
        IE *p2=head;
        while(p2!=NULL)
        {
                printf("%s\t%s\t%s\n",p2->tag,p2->length,p2->value);
                p2=p2->next;
        }
}
IE* paixu(IE* p,IE* head)
{
	IE *p1;
	IE *p2;
	p1=p2=head;
	while(p1!=NULL&&strcmp(p->tag,p1->tag)>=0)
	{
		p2=p1;
		p1=p1->next;
	}
	if(p1==p2)
	{
		p->next=head;
		head=p;
	}
	else
	{
		p->next=p1;
		p2->next=p;
	}
	return head;
}
                    
int main()
{
	char ch;
	int num=0;
	int flag=0;
	IE* head=NULL;
	int i=0,j=0;
	printf("请输入十六进制数:\n");
	while(flag==0)
	{
		IE* p=malloc(sizeof(IE));
		if(flag!=1)
		{
		for(i=0;i<8;i++)
		{
		 	scanf("%c",&ch);
			if(ch=='\n')
                        {
                                flag=1;
                                break;
                        }
			p->tag[i]=ch;
		}
		}
		if(flag!=1)
		{
		for(j=0;j<4;j++)
		{
			num=num<<4;
			scanf("%c",&ch);
			if(ch=='\n')
                        {
                                flag=1;
                                break;
                        }
			p->length[j]=ch;
			num=length_num(ch,num);
		}
		}
		if(flag!=1)
		{
		p->value=malloc(2*num+1);
		for(i=0;i<(2*num);i++)
		{
			scanf("%c",&ch);
			if(ch=='\n')
                        {
                                flag=1;
                                break;
                        }
			p->value[i]=ch;
		}
		}
		if(flag==1)
		{
			free(p);
		}
		else
		{
		head=paixu(p,head);
		}
		num=0;
	}
	printf_link(head);
	return 0;
}
