#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/types.h>
#include "demo.h"
struct mydev 
{
	struct miscdevice *demoled;
	int data[5];
	int i;
};
struct mydev *mydev;
void stack_push(int n)
{
	if(mydev->i==5)
	{
		return ;
	}
	mydev->data[mydev->i]=n;
	mydev->i++;
}
int  stack_pop(struct mydev *mydev)
{
	if(mydev->i==0)
	{
		return 0;
	}
	mydev->i--;
//	arg=mydev->data[mydev->i];
	return mydev->data[mydev->i];
//	printk(KERN_INFO "%d",arg);
	
}
static long ok6410_leds_unlocked_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
	if(cmd==CMD2)
	{
	printk(KERN_INFO "shu chu %d",stack_pop(mydev));
	mydev->i--;
	copy_to_user((int *)arg,(int *)mydev->data+mydev->i,sizeof(int));
	}
	if(cmd==CMD1)
	{
		stack_push((int)arg);
	}
        return 0;
}
int demo_open(struct inode *inode,struct file *filp)
{
//	struct mydev *pmydev=NULL;
	printk(KERN_INFO "Call demo_open.\n");
//	filp->private_data=pmydev;
	return 0;
}
int demo_release(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "Call demo_release.\n");
	return 0;
}
/*ssize_t demo_read(struct file *filp,char __user *buff,size_t count,loff_t *lofp)
{
//	struct mydev *pmydev=NULL;
//	pmydev=(struct mydev *)(filp->private_data);
	copy_to_user(buff,mydev->data,count);
	printk(KERN_INFO "Call demo_read:%lu\n",count);
	return count;
}
ssize_t demo_write(struct file *filp,const char __user *buff,size_t count,loff_t *lofp)
{
//	struct mydev *pmydev=NULL;
//	pmydev=(struct mydev *)(filp->private_data);
	copy_from_user(mydev->data,buff,count);
	printk(KERN_INFO "Call demo_write.:%lu\n",count);
	return count;
}
*/
static struct file_operations dev_fops={
        .owner  = THIS_MODULE,
        .unlocked_ioctl = ok6410_leds_unlocked_ioctl,
	.open   = demo_open,
	.release = demo_release,
//	.read   =  demo_read,
//	.write  =  demo_write,
};

static struct miscdevice demoled={
        .minor  = MISC_DYNAMIC_MINOR,
        .name   = DEVICE_NAME,
        .fops   = &dev_fops,
};

static int __init dev_init(void)
{
	mydev=kzalloc(sizeof(struct mydev),GFP_KERNEL);
//	mydev->data=kzalloc(100,GFP_KERNEL);
	mydev->i=0;
	mydev->demoled=&demoled;
        misc_register(&demoled);
        printk(KERN_INFO "%s initialized\n",DEVICE_NAME);
        return 0;
}

static void __exit dev_exit(void)
{
        printk(KERN_INFO "%s exited\n",DEVICE_NAME);
	kfree(mydev);
        misc_deregister(&demoled);
//	kfree(mydev->data);
}

module_init(dev_init);
module_exit(dev_exit);
