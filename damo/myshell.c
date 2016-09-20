#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	char cmd[100];
	int rt;
	int i=0;
	int j=0;
	char * arrcmd[100]={NULL};
	while(1)
	{
		printf("wyj :");
		gets(cmd);
		if(strcmp(cmd,"exit")==0)
		{
			break;
		}
		i=0;
		j=0;
		while(cmd[i]!='\0')
		{
			if(cmd[i]!=' '&&(i==0||cmd[i-1]=='\0'))	
			{
				arrcmd[j]=cmd+i;
				j++;
			}
			if(cmd[i]==' ')
			{
				cmd[i]='\0';
			}
			i++;
		}
		if(fork()==0)
		{
			execvp(arrcmd[0],arrcmd);
		}
		wait(&rt);
		memset(arrcmd,0,sizeof(arrcmd));
	}
	return 0;
}
