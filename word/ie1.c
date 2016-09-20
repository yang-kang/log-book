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
int getie(IE *p)
{
	char ch;
        int num=0;
	int i=0,j=0;
	p=malloc(sizeof(IE));
	for(i=0;i<8;i++)
        {
		scanf("%c",&ch);
              	if(ch=='\n')
      	        {
        	       	return 1;
               	}
               	p->tag[i]=ch;
        }
	printf("%s",p->tag);
    	for(j=0;j<4;j++)
       	{
             	num=num<<4;
              	scanf("%c",&ch);
               	if(ch=='\n')
               	{
             		return 1;
              	}
           	p->length[j]=ch;
            	num=length_num(ch,num);
      	}
       	for(i=0;i<(2*num);i++)
       	{
    		scanf("%c",&ch);
            	if(ch=='\n')
            	{
                       	return 1;
            	}
           	p->value[i]=ch;
     	}
	return 0;
}
IE *getTLV(IE *head)
{
	IE* p=NULL;
	int flag=0;
        while(1)
        {
                p=malloc(sizeof(IE));
//                flag=getie(p);
                if(flag==0)
                {
                        head=paixu(p,head);
                }
                else
                {
                        free(p);
                        break;
                }
        }
	return head;
}
int main()
{
	IE* head=NULL;

	head=malloc(sizeof(IE));
	getie(head);
	head=getTLV(head);

	printf_link(head);
	return 0;
}
