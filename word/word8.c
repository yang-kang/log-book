#include<stdio.h>
#include<stdlib.h>

static int i=0;
int* push_fun(int *p,int len)
{
	if(i==len)
	{
		printf("栈满！\n");
		return p;
	}
	*(p+i)=i;
	i++;
	return p;
}
int pop_fun(int *p)
{
	if(i==0)
	{
		printf("栈空！\n");
		return 0;
	}
	i--;
	*(p+i)=i;
	return *(p+i);
}
int main()
{
	int *p=NULL;
	int len=10;
	p=malloc(sizeof(int)*len);
	p=push_fun(p,len);
	p=push_fun(p,len);
	p=push_fun(p,len);
	p=push_fun(p,len);
	printf("%d\n",pop_fun(p));
	p=push_fun(p,len);
	p=push_fun(p,len);
	printf("%d\n",pop_fun(p));
	return 0;
}
