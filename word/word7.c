#include<stdio.h>

int countlen(int n)
{
	int i=0;
	do
	{
		n=n>>1;
		i++;
	}while(n>0);
	return i;
}
void qiandao(int m)
{
	int i=0;
	for(i=0;i<m-1;i++)
	{
		printf("1");
	}
	printf("0");
}
void houdao(int n, int m)
{
	int i=0;
	for(i=m-1;i>=0;i--)
	{
		if((n>>i)&1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}
int main()
{
	char tmp=0;
	int i=0,j=0;
	int flag=0;
	while(flag==0)
	{
		scanf("%c",&tmp);
		switch(tmp)
		{
			case '0':
				i++;
				break;
			case '1':
				j=countlen(i);
				qiandao(j);
				houdao(i,j);
				i=0;
				break;
			case '\n':
				flag=1;
				break;
			default :
				break;
		}
	} 
	printf("\n");
	return 0;
}
