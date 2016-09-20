#include <stdlib.h>
#include <stdio.h>
#include "mysql.h"

int main(int argc, char *argv[]) 
{
	FILE * fp=NULL;
	char ch;
	int m;
	int i=0,j=0;
	char arr[200][100]={""};
	fp=fopen("create1.sql","r");
	while(fscanf(fp,"%c",&ch)!=EOF)
	{
		if(ch!=';')
		{
 			arr[i][j]=ch;
			j++;
		}
		if(ch==';')
                {
			arr[i][j]=ch;
			i++;
			j=0;
		}
	}
	fclose(fp);
    	
	MYSQL my_connection;
    	int res;
    	mysql_init(&my_connection);
    	if (mysql_real_connect(&my_connection, "localhost", "root", "yk", "shop", 0, NULL, 0)) 
    	{
        printf("Connection success\n");
        res = mysql_query(&my_connection, arr[i]);
        if (!res) {
            printf("Inserted %lu rows\n",
                    (unsigned long)mysql_affected_rows(&my_connection));
        } else {
            fprintf(stderr, "Insert error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        }

        mysql_close(&my_connection);
    } else {
        fprintf(stderr, "Connection failed\n");
        if (mysql_error(&my_connection)) {
            fprintf(stderr, "Connection error %d: %s\n", mysql_errno(&my_connection), mysql_error(&my_connection));
        }
    }
	
	printf("%s\n",arr[i]);
	i++;
	}
    return EXIT_SUCCESS;
}
