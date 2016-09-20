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
	char *data;
};
struct mydev *mydev;
/*static int ok6410_leds_ioctl(struct inode *inode,struct file *file,unsigned int cmd,unsigned long arg)
{
        return 0;
}*/
static long ok6410_leds_unlocked_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
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
ssize_t demo_read(struct file *filp,char __user *buff,size_t count,loff_t *lofp)
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

static struct file_operations dev_fops={
        .owner  = THIS_MODULE,
        .unlocked_ioctl = ok6410_leds_unlocked_ioctl,
	.open   = demo_open,
	.release = demo_release,
	.read   =  demo_read,
	.write  =  demo_write,
};

static struct miscdevice demoled={
        .minor  = MISC_DYNAMIC_MINOR,
        .name   = DEVICE_NAME,
        .fops   = &dev_fops,
};

static int __init dev_init(void)
{
        printk(KERN_INFO "%s initialized\n",DEVICE_NAME);
	mydev=kzalloc(sizeof(struct mydev),GFP_KERNEL);
	mydev->data=kzalloc(100,GFP_KERNEL);
	mydev->demoled=&demoled;
        misc_register(&demoled);
        return 0;
}

static void __exit dev_exit(void)
{
        printk(KERN_INFO "%s exited\n",DEVICE_NAME);
        misc_deregister(&demoled);
	kfree(mydev->data);
	kfree(mydev);
}

module_init(dev_init);
module_exit(dev_exit);
