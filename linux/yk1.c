#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/semaphore.h>
#include <linux/types.h>
#include "demo.h"
struct mydev 
{
	struct miscdevice *demoled;
	struct semaphore sem; 
	int *data;
	int size;
	int count;
	int i_p;
	int i_c;
};
struct mydev *mydev;

int producer(unsigned long arg)
{
        if(mydev->count<mydev->size)
        {
                mydev->data[mydev->i_p]=arg;
                mydev->i_p++;
                if(mydev->i_p==mydev->size)
                {
                        mydev->i_p=0;
                }
                mydev->count++;
        }
	return 0;
}
int consumer(void)
{
	int d=0;
        if(mydev->count>0)
        {
                d=mydev->data[mydev->i_c];
                mydev->i_c++;
                if(mydev->i_c==mydev->size)
                {
                        mydev->i_c=0;
                }
                mydev->count--;
        }
 	return d;
}

static long ok6410_leds_unlocked_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
	if(cmd==CMD2)
	{
		copy_to_user((int *)arg,(int *)mydev->data+mydev->i_c,sizeof(int));
		printk(KERN_INFO "shu chu1 %d\n",consumer());
//		mydev->count--;
        }
	
	
	if(cmd==CMD1)
	{
		printk(KERN_INFO "shu chu2 %d\n",mydev->data[mydev->i_c]);
		producer((int)arg);

	}
        return 0;
}
int demo_open(struct inode *inode,struct file *filp)
{
//	struct mydev *pmydev=NULL;
	printk(KERN_INFO "Call demo_open.\n");
  	if(down_interruptible(&(mydev->sem)))
	{
		return -ERESTARTSYS;
	}
//	filp->private_data=pmydev;
	return 0;
}
int demo_release(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "Call demo_release.\n");
	up(&(mydev->sem));
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
	mydev->data=kzalloc(sizeof(int)*100,GFP_KERNEL);
	sema_init(&(mydev->sem),1);
	mydev->i_p=0;
	mydev->i_c=0;
	mydev->count=0;
	mydev->size=100;
	mydev->demoled=&demoled;
        misc_register(&demoled);
        printk(KERN_INFO "%s initialized\n",DEVICE_NAME);
        return 0;
}

static void __exit dev_exit(void)
{
        printk(KERN_INFO "%s exited\n",DEVICE_NAME);
	kfree(mydev->data);
	kfree(mydev);
        misc_deregister(&demoled);
}

module_init(dev_init);
module_exit(dev_exit);
