#include<stdio.h>

struct xinxi
{
	char name[10];
	int sex;
	char id[12];
	int age;
	char tel[12];
};
void get_xinxi(struct xinxi *p)
{
	printf("请输入姓名：\n");
	scanf("%s",p->name);
	printf("请输入性别（0.女，1.男）：\n");
	scanf("%d",&(p->sex));
	printf("请输入学号：\n");
	scanf("%s",p->id);
	printf("请输入年龄：\n");
	scanf("%d",&(p->age));
	printf("请输入电话：\n");
	scanf("%s",p->tel);
}
void put_xinxi(struct xinxi *p)
{
	printf("%s\t",p->name);
	switch(p->sex)
	{
		case 0:printf("女\t");break;
		case 1:printf("男\t");break;
		default :printf(" \t");break;
	}
	printf("%s\t%d\t%s\n",p->id,p->age,p->tel);
}

int main()
{
	struct xinxi arr[5];
	int i=0;
	for(i=0;i<5;i++)
	{
	 	get_xinxi(arr+i);
	}
	for(i=0;i<5;i++)
	{
		put_xinxi(arr+i);
	}
	return 0;
}
