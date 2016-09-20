#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include"demo.h"
int main(int argc,char **argv)
{
	int fd;
	int s,m;
	int sel=0;

	fd=open("/dev/yk",O_RDWR);
	do
	{
		printf("请输入：1.生产数据;2.消费数据;0.退出。");
		scanf("%d",&sel);
		switch(sel)
		{
			case 1:
	    			scanf("%d",&m);
				ioctl(fd,CMD1,m);
				break;
			case 2:
				ioctl(fd,CMD2,&s);
				printf("%d\n",s);
				break;
			case 0:
				break;
			default:
				break;
		}
	}while(sel);
	close(fd);
	return 0;
	
}
