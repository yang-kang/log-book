/*ioctl
2.6代码支持ioctl和unlocked_ioctl，两个都存在时，用户ioctl优先调用unlocked_ioctl
3.0代码去掉了对ioctl的支持。
用户空间原型 int ioctl(int fd,unsigned long cmd, ...);
驱动程序的ioctl和unlocked_ioctl原型如下：
int (*ioctl)(struct inode *inode,struct file *filp,unsigned int cmd, unsigned long arg);
long (*unlocked_ioctl)(struct file *filp,unsigned int cmd,unsigned long arg);
inode和filp对应用户空间应用程序传递的文件描述符fd，
cmd由用户空间不经修改的传递给驱动程序，
可选的参数arg则无论用户程序使用的是指针还是整数值，都以unsigned long的形式传递给驱动程序。如果调用程序没有传递第三个参数，那么驱动程序所接受到的arg就处在未定义状态。
为了防止对错误的设备使用正确的命令，命令号应该在系统范围内唯一。
为方便程序员创建唯一的ioctl命令号，定义号码的方法使用了4个位字段，含义如下：
type	幻数。避免了和别的设备的冲突
number	序数。命令顺序编号。
direction	若命令涉及到数据的传输，则该位字段定义数据传输方向。
size	用户数据大小。
在linux/ioctl.h中包含的头文件asm/ioctl.h中定义了一些构造命令编号的宏:
_IO（type,nr）;构造无参数的命令编号
_IOR(type,nr,datatype);构造读数据的命令编号
_IOW(type,nr,datatype);构造写数据的命令编号
_IOWR(type,nr,datatype);构造双向传输
type和nr:bumber通过参数传入，size参数通过对datatype参数取sizeof获得。
通过下面宏可以从cmd中解出4位.

*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include "demo.h"
/*static int ok6410_leds_ioctl(struct inode *inode,struct file *file,unsigned int cmd,unsigned long arg)
{
	return 0;
}*/
static long ok6410_leds_unlocked_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
	//printk("cmd:%d\narg:%s",cmd,arg);
	printk(KERN_INFO "cmd:%d\nnoarg",cmd);
	return 0;
}

static struct file_operations dev_fops={
	.owner	= THIS_MODULE,
//	.ioctl	= ok6410_leds_ioctl,
	.unlocked_ioctl	= ok6410_leds_unlocked_ioctl,
};

static struct miscdevice demoled={
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= DEVICE_NAME,
	.fops	= &dev_fops,
};

static int __init dev_init(void)
{
	printk(KERN_INFO "%s initialized\n",DEVICE_NAME);
	misc_register(&demoled);
	return 0;	
}

static void __exit dev_exit(void)
{
	printk(KERN_INFO "%s exited\n",DEVICE_NAME);
	misc_deregister(&demoled);
}

module_init(dev_init);
module_exit(dev_exit);
