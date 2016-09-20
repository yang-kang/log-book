#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include"demo.h"

int main(int argc,char **argv)
{
	int fd;
	int i;
	fd=open("/dev/yk",O_RDWR);
	for(i=0;i<100;i++)
	{
		ioctl(fd,CMD1,i);
	}
	close(fd);
	return 0;
}
