#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *p=NULL;
	char *p1=NULL;
	char *p2=NULL;
	char *arr[100]={NULL};
	int i=0,j=0;
	char *buff;
	int n=0,m=0,num=0,count=0;
	p=(char *)malloc(sizeof(char));
	p1=p;
	p2=p;
	while((p[i]=getchar())!='\n')
	{
		i++;
	}
	i=0;
	while(p1[i]!='\0')
	{
		i++;
	}
	while(i>=0)
	{
		if(p1[i-1]==' '||(i==0))
		{
			arr[j]=&p1[i];
			p1[i-1]='\0';
//		printf("%s",arr[j]);
			j++;
		}
		i--;
	}

	i=0;
	while(arr[i]!=NULL)
	{
		j=0;
		buff=arr[i];
		while(*(arr[i]+j)!='\0')
		{
			if(((*(arr[i]+j)>='a'&&*(arr[i]+j)<='z')&&(*(arr[i]+j+1)>='a'&&*(arr[i]+j+1)<='z'))||((*(arr[i]+j)>='A'&&*(arr[i]+j)<='Z')&&(*(arr[i]+j+1)>='A'&&*(arr[i]+j+1)<='Z')))
			{	
				num=j;
				count++;
			}
			j++;
		}
		printf("%d\n",count);
		m=num+1;
		n=m-count;
		printf("-----%s\n",buff);
		for(j=0;j<=count;j++)
		{
			*(arr[i]+n)=buff[m];
		printf("m:%d\n",m);
		printf("====%c\n",*(arr[i]+n));
			n++;
			m--;
		}
		printf("%s\n",arr[i]);
		i++;
		count=0;
	}
}
