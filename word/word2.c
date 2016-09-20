#include<stdio.h>
#define N 10
void zhuanhuan(char* str);
int geshu(char* str1,char b);
int danci(char* str2);

int main()
{
   	char n;
	char arry[N]={0};
	
	printf("请输入字符串：\n");	 
	gets(arry);
	printf("%s\n",arry);
	zhuanhuan(arry);
	printf("%s\n",arry);
	
	printf("请输入转换后指定的字符：\n");
	scanf(" %c",&n);

	printf("%d\n",geshu(arry,n));
	printf("%d\n",danci(arry));
	return 0;
}
void zhuanhuan(char* str)
{
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]>96&&str[i]<123)
		{
			str[i]-=32;
		}
		i++;
	}
}
int geshu(char* str1,char b)
{
	int a=0;
	int num=0;
	while(str1[a]!='\0')
	{
		if(str1[a]==b)
		{
			num+=1;
		}
		a++;
	}
	return num;
}
int danci(char* str2)
{
	int i=0;
	int m=0;
	while(str2[i]!='\0')
	{
		if(str2[i]!=' '&&(str2[i+1]==' '||str2[i+1]=='\0'))
		{
			m+=1;
		}
	
		i++;
	}
	return m;
}
