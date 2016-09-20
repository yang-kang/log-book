#include<linux/ioctl.h>
#ifndef __DEMO_H
#define __DEMO_H
#define DEVICE_NAME "yk"
unsigned int  CMD1=_IOW(1,1,int );
unsigned int CMD2=_IOR(1,2,int*);
#endif
