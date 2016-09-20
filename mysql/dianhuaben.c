#include <stdlib.h>
#include <stdio.h>
#include "mysql.h"
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	FILE *fp=NULL;
    	int res;
	int res1;
	int res2;
	char arr[10]="";
	char arr1[20]="create database ";
	char arr2[10]="";
	char arr3[10]="";
	char arr4[30]="create table ";
	char arr5[10]="";
	char arr6[10]="use ";
	char arr7[200]="(id integer not null auto_increment,name varchar(15),sex varchar(5),relation varchar(20),tel varchar(15),PRIMARY KEY(`id`));";
	char *p=NULL;
	fp=fopen("data","w");

	printf("请输入用户：\n");
	scanf("%s",arr3);
	fprintf(fp,"%s\n",arr3);
	printf("用户密码：\n");
	scanf("%s",arr2);
	fprintf(fp,"%s\n",arr2);
	printf("请输入数据库名：\n");
	scanf("%s",arr);
	fprintf(fp,"%s\n",arr);
	printf("请输入数据库表名：\n");
	scanf("%s",arr5);
	fprintf(fp,"%s",arr5);
	fclose(fp);
	p=malloc(sizeof(char)*200);
	p=strcat(arr4,arr5);

	MYSQL my_connection;
    	mysql_init(&my_connection);
    	if (mysql_real_connect(&my_connection, "localhost", arr3, arr2, "mysql", 0, NULL, 0)) 
    	{
        	printf("Connection success\n");
        	res = mysql_query(&my_connection, strcat(arr1,arr));
		res1= mysql_query(&my_connection, strcat(arr6,arr));
		res2= mysql_query(&my_connection, strcat(p,arr7));
        	if (!res2&&(!res)&&(!res1)) 
		{
            		printf("Inserted %lu rows\n",(unsigned long)mysql_affected_rows(&my_connection));
        	} 
		else 
		{
            		fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        	}

        	mysql_close(&my_connection);
    	} 
	else 
	{
        	fprintf(stderr, "Connection failed\n");
        	if (mysql_error(&my_connection)) 
		{
            		fprintf(stderr, "Connection error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        	}
	}
    	return EXIT_SUCCESS;
}
