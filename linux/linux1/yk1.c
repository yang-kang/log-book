#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
dev_t dev_id;

/*定义设备结构体*/
struct mydev 
{
	struct cdev cdev;
	int count;//用来统计设备被打开个数
	char *data;//设备私有数据
	loff_t r_i;
	loff_t w_i;
};
struct mydev *mydev;

int demo_open(struct inode *inode,struct file *filp)
{
	struct mydev *pmydev=NULL;
	printk(KERN_INFO "Call demo_open.\n");
	//从inode取出cdev指针
	//从cdev指针container_of得到mydev指针
	pmydev=container_of(inode->i_cdev,struct mydev,cdev);
	//若需要，为mydev申请资源
	//将mydev指针存到filp->private_data;
	filp->private_data=pmydev;
	return 0;
}

int demo_release(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "Call demo_release.\n");
	/*
		若mydev有申请资源，则此处应该释放
	*/
	return 0;
}

ssize_t demo_read(struct file *filp,char __user *buff,size_t count,loff_t *lofp)
{
	//从filp中得到mydev指针，
	struct mydev *pmydev=NULL;
	pmydev=(struct mydev *)(filp->private_data);
	//从mydev指针指向的mydev结构体中取出资源，
	
	//使用copy_to_user,将需要的资源传递给用户层
	copy_to_user(buff,pmydev->data+pmydev->r_i,count);
	printk(KERN_INFO "Call demo_read:%lu\n",count);
	pmydev->r_i+=count;
	return count;
}

ssize_t demo_write(struct file *filp,const char __user *buff,size_t count,loff_t *lofp)
{
	struct mydev *pmydev=NULL;
	//从filp中得到mydev指针
	pmydev=(struct mydev *)(filp->private_data);
	//从mydev指针指向mydev结构体中取出资源
	//使用copy_from_user，将用户层数据存储到资源中。
	copy_from_user(pmydev->data+pmydev->w_i,buff,count);
	printk(KERN_INFO "Call demo_write.:%lu\n",count);
	mydev->w_i+=count;
	return count;
}

struct file_operations fops={
	.owner		= THIS_MODULE,
	.open		= demo_open,
	.release	= demo_release,
	.read		= demo_read,
	.write		= demo_write,
};


static int __init demo_init(void)
{
	int err;
	printk(KERN_INFO "demo init success!\n");
	alloc_chrdev_region(&dev_id,0,4,"demo_dev");//申请设备号
	mydev=kmalloc(sizeof(struct mydev),GFP_KERNEL);
	if(mydev==NULL)
	{
		printk(KERN_INFO "Error: alloc mydev fail!\n");
		goto FAIL1;
	}
	memset(mydev,0,sizeof(struct mydev));
	cdev_init(&(mydev->cdev),&fops);
	mydev->cdev.owner=THIS_MODULE;
	mydev->data=(char *)kmalloc(100,GFP_KERNEL);
	if(mydev->data==NULL)
	{
		printk(KERN_INFO "mem alloc fail\n");
		goto FAIL2;
	}
	mydev->r_i=0;
	mydev->w_i=0;
	err=cdev_add(&(mydev->cdev),dev_id,4);
	if(err)
	{
		printk(KERN_NOTICE "Error %d adding demo_dev.",err);
		goto FAIL4;
	}
	return 0;

	FAIL4:
		kfree(mydev->data);	
		err=-4;
	//FAIL3:
	//	kfree(mydev->cdev);
	//	err=-3;
	FAIL2:
		kfree(mydev);
		err=-2;
	FAIL1:
		unregister_chrdev_region(dev_id,4);
		err=-1;
		printk(KERN_NOTICE "Error  %d adding demo_dev.",err);
		
		return -1;
}

static void __exit demo_exit(void)
{
	printk(KERN_INFO "demo exit success!\n");
	cdev_del(&(mydev->cdev));
	kfree(mydev->data);	
	//kfree(mydev->cdev);
	kfree(mydev);
	unregister_chrdev_region(dev_id,4);
	return;
}

module_init(demo_init);
module_exit(demo_exit);
