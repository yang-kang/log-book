#include<stdio.h>

void put(int m)
{
	int i=0;
	for(i=0;i<m;i++)
	{
		printf("0");
	}
	printf("1");
}
int main()
{
	char arr[]="11001011100110";
	int i=0,num=0;
	int count=0,a=0;
	while(arr[a]!='\0')
	{
		if(arr[a]=='1')
		{
			count++;
			a++;
		}
		else
		{
					printf("%c\n",arr[a]);
			printf("%d",a);
			for(i=count;i>=0;i--)
			{
				if(arr[a]==1)
				{
					for(int j=1;j<=i;j++)
					{
						j=j*2;
						num=2*j+num;
						put(num);
					}
				}
				a++;
			}
			num=0;
			count=0;
		}
		sleep(1);
			
	}
	return 0;

}
