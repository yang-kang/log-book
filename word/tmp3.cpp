#include<iostream>
using namespace std;

template<class X>
void paixu(X arr[10])
{
	int i=0,j=0;
	X temp=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main()
{
	int i=0;
	int arr[10]={1,2,9,3,8,5,4,6,7};
	paixu(arr);
	for(i=0;i<10;i++)
	{
		cout<<arr[i]<<endl;
	}
}
