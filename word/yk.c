#include <stdio.h>
#include <string.h>

int main()
{
	char str[129]="";
	char ch;
	int i=0;
	int n=0;
	int arr[64]={0};
	int j=0;
	int temp;
	//得到用户输入
	i=0;
	while((ch=getchar())!='\n')
	{
		str[i]=ch;
		i++;
	}
	//将输入转化为数字
	if(strlen(str)==0)
	{
		printf("0,0");
		return 0;
	}
	i=0;
	n=0;
	j=0;
	while((ch=str[i])!='\0')
	{
		if(ch=='-')
		{
			if(str[i+1]!=','&&str[i+1]!='\0')
      		        {
                        	n*=10;
                        	n+=(str[i+1]-'0');
				arr[j]=-n;
				n=0;
				j++;
			}
			i+=3;
		}
		else
		{
			ch=str[i];
			if(ch!=','&&ch!='\0')
			{
				n*=10;
				n+=(ch-'0');
			}
			else
			{
				arr[j]=n;
				n=0;
				j++;
				if(ch=='\0')
				{
					break;
				}
			}
			i++;
		}	
	}
	if(j==1)
	{
		printf("%d,%d",arr[0],arr[0]);
		return 0;
	}
	//2个及以上数
	n=j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("%d,%d",arr[n-1],arr[n-2]);
	return 0;
} 
