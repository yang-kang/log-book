#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include"demo.h"
int main(int argc,char **argv)
{
	int fd;
	int s,i;
	fork();
	fork();
	fd=open("/dev/yk",O_RDWR);
	for(i=0;i<20;i++)
	{
			ioctl(fd,CMD2,&s);
			printf("%d\n",s);
	}
	close(fd);
	return 0;
}
