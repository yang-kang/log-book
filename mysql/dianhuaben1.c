#include <stdlib.h>
#include <stdio.h>
#include "mysql.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
	FILE *fp=NULL;
	int n;
	int flag=1;
	char arr1[20]="";
	char arr2[20]="";
	char arr3[20]="";
	char arr4[40]="";
	char arr5[100]="insert into ";
	char arr6[50]="(name,sex,relation,tel) values(";
	char *p=NULL;
	char arr7[3]="'";
	char arr8[100]="";
	char arr9[100]="";
	char arr10[100]="";
	char arr11[100]="";
	char arr12[5]=");";
	char arr13[5]=",";
	char arr14[20]="";
	char arr15[20]="";
	char arr16[20]="update ";
	char arr17[20]=" set name= ";
	char arr18[30]=" where name = ";
	char arr19[30]="delete from ";
	char arr20[20]="";
	char arr21[30]=" where name = '";

	fp=fopen("data","r");
	fscanf(fp,"%s",arr1);
	fscanf(fp,"%s",arr2);
	fscanf(fp,"%s",arr3);
	fscanf(fp,"%s",arr4);
	fclose(fp);

	MYSQL my_connection;
    	int res;
    	mysql_init(&my_connection);
    	if (mysql_real_connect(&my_connection, "localhost", arr1, arr2, arr3, 0, NULL, 0)) 
    	{
        printf("Connection success\n");
	while(flag)
	{
		printf("请用户选择：0.退出，1.添加，2.修改，3.删除\n");
        	scanf("%d",&n);
		p=NULL;
		p=malloc(sizeof(char)*200);

	       	char arr5[100]="insert into ";
		char arr8[100]="";
	        char arr9[100]="";
        	char arr10[100]="";
        	char arr11[100]="";
		char arr14[20]="";
	        char arr15[20]="";
        	char arr16[20]="update ";
		char arr19[30]="delete from ";
        	char arr20[20]="";
		char arr21[30]=" where name = '";

		switch(n)
		{
			case 0:flag=0;break;
			case 1:
				p=strcat(arr5,arr4);    	
				p=strcat(p,arr6);
				printf("请输入姓名\n");
				scanf("%s",arr8);
				p=strcat(p,arr7);
				p=strcat(p,arr8);
				p=strcat(p,arr7);
				p=strcat(p,arr13);
			
				printf("请输入性别\n");
                        	scanf("%s",arr9);
                        	p=strcat(p,arr7);
                        	p=strcat(p,arr9);
                        	p=strcat(p,arr7);
				p=strcat(p,arr13);
			
			 	printf("请输入关系\n");
                        	scanf("%s",arr10);
                        	p=strcat(p,arr7);
                        	p=strcat(p,arr10);
                        	p=strcat(p,arr7);
				p=strcat(p,arr13);
			
			 	printf("请输入电话\n");
                        	scanf("%s",arr11);
				printf("222222222");
                        	p=strcat(p,arr7);
				printf("111111111");
                        	p=strcat(p,arr11);
                        	p=strcat(p,arr7);
				p=strcat(p,arr12);
				printf("%s\n",p);
       		 		res = mysql_query(&my_connection,p);
				if (!res) 
        			{
                			printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(&my_connection));
        			} 
        			else  
        			{
                			fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        			}
				
				break;
			case 2:
				printf("请输入要修改的的名字\n");
				scanf("%s",arr14);
				printf("请输入要更改的名字\n");
				scanf("%s",arr15);
				p=strcat(arr16,arr4);
				p=strcat(p,arr17);
				p=strcat(p,arr7);
				p=strcat(p,arr15);
				p=strcat(p,arr7);
				p=strcat(p,arr18);
				p=strcat(p,arr7);
				p=strcat(p,arr14);
				p=strcat(p,arr7);
				res = mysql_query(&my_connection,p);
				if (!res) 
        			{
                			printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(&my_connection));
        			} 
        			else  
        			{
                			fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        			}

				break;	
			case 3:
				printf("请输入删除人的姓名：\n");
				scanf("%s",arr20);
				p=strcat(arr19,arr4);
				p=strcat(p,arr21);
				p=strcat(p,arr20);
				p=strcat(p,arr7);
				printf("%s\n",p);
				res = mysql_query(&my_connection,p);
				if (!res) 
        			{
                			printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(&my_connection));
        			} 
        			else  
        			{
                			fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        			}
				break;
		}
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
