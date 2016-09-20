#include<stdio.h>

#define a 3
#define b 5
#define c 7

int main()
{
	int arr[100];
	int i=0;
	for(i=0;i<100;i++)
	{
		arr[i]=i+1;
	}
	i=0;
	while(i<100)
	{
		if(arr[i]/10==a||arr[i]%10==a)
		{
			printf("%d->Fizz\n",arr[i]);
			i++;
		}
		else if(arr[i]%3==0)
		{
			if((arr[i]%3==0)&&(arr[i]%5==0))
			{	
				if((arr[i]%3==0)&&(arr[i]%5==0)&&(arr[i]%7==0))
				{
					printf("%d->FizzBuzzWhizz\n",arr[i]);
					
				}
				else
				{
				printf("%d->FizzBuzz\n",arr[i]);
				}
			}
			else
			{
				printf("%d->Fizz\n",arr[i]);
			}
			i++;
		}
		else if(arr[i]%5==0)
		{
			if((arr[i]%5==0)&&(arr[i]%7==0))
			{
				printf("%d->BuzzWhizz\n",arr[i]);
			}
			else
			{
				printf("%d->Buzz\n",arr[i]);
			}
			i++;
		}
		else if(arr[i]%7==0)
		{
			printf("%d->Whizz\n",arr[i]);
			i++;
		}
		else
		{
				
			printf("%d\n",arr[i]);
			i++;
		}
	}
	return 0;
}
