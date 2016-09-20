#include<stdio.h>
#define N 10
#include"word11.h"
int main()
{
	char arry[N]={0};
        char ch;
	char *arr1[10]={NULL};
	int n=0,i=0;

        printf("请输入字符串：\n");
        gets(arry);
        printf("请输入指定字符：\n");
        scanf("%c",&ch);
	printf("指定字符的个数：%d\n",tongji(arry,ch));
	printf("单词的个数：%d\n",geshu(arry));
	n=geshu(arry);
	str2word(arry,arr1);
	for(i=0;i<n;i++)
	{
		printf("第%d个单词：%s\n",i,arr1[i]);
	}
//	x2d(arry);
//	puts(arry);
        return 0;

}

