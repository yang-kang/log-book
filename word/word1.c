#include<stdio.h>

int strbj(char *str1,char *str2);
int strcopy(char *str1,char *str2);

int main()
{
	char str[5][10]={"abc","acd","jkuy","cde","gfe"};
	int bj=0;
	int i=0,j=0;
	char temp[10]={0};
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
		 	bj=strbj(str[i],str[i+1]);
			if(bj<0)
			{
				strcopy(temp,str[j]);
				strcopy(str[j],str[j+1]);
				strcopy(str[j+1],temp);
			}
		}
	
	printf("%s\n",str[i+1]);	
	}	
	return 0;
}
int strbj(char *str1,char *str2)
{
	int i=0;
	while(str1[i]!='\0'&&str2[i]!='\0')
	{
		if(str1[i]!=str2[i])
		{
			break;
		}
		i++;
	}
	return str1[i]-str2[i];
}
int strcopy(char *str1,char *str2)
{
	int l=0;
	while(str2[l]!='\0')
	{
		str1[l]=str2[l];
		l++;
	}
	return l;
}
