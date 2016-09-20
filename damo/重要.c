1.
头文件: #include<linux/cdev.h>
函数名称: cdev_add
功能: 将cdev-add模块添加到系统中
使用方法: int cdev_add(struct cdev *cdev,dev_id devno,unsigned int,count)
参数解释: 
	 cdev,要加载的模块结构体
	 devno,设备号
	 count,一次加载的设备个数
返回值: 表示函数的运行结果，0为正常，非零为错误。
2.
头文件:#include<linux/fs.h>
函数名称:alloc_chrdev_region
功能:申请设备号
使用方法:alloc_chrdev_region(&dev_id,0,4,"demo_dev");
参数解释:dev_id是一个用来存放设备号的变量，0是指人不给它分配设备号由系统自动进行分配，4是指的次设备号，demo_dev是指的插入进去的模块的名字。
返回值: 没有返回值
3.
头文件: #include<linux/string.h>
函数名称:memset
功能:对申请来的内存进行初始化
使用方法:memset(mydev,0,sizeof(struct mydev));
参数解释:mydev是要初始化的东西，0是要把mydev初始化为0,sizeof(struct mydev)是要初始化的mydev的大小
返回值:没有返回值
4.
头文件:#include<linux/cdev.h>
函数名称:cdev_init
功能:字符设备的注册
使用方法:cdev_init(&(mydev->cdev),&fops)
参数解释:
返回值:
5.
头文件:#include<linux/cdev.h>
函数名称:cdev_del
功能:模块的卸载
使用方法:cdev_del(&(mydev->cdev));
参数解释:&(mydev->cdev)就是要卸载的东西的地址
返回值:没有返回值
6.
头文件:#include<linux/fs.h>
函数名称:unregister_chrdev_region
功能:在调用 cdev_del()函数从系统注销字符设备之后，unregister_chrdev_region()应该被调用以释放原先申请的设备号。
使用方法:unregister_chrdev_region(dev_id,4);
参数解释:dev_id为申请的设备号，4也就是前面的count为申请的设备数量。
返回值:无返回值
7.
头文件:#include<linux/fs.h>
函数名称:register_chrdev_region
功能:注册一组字符的设备编号。
使用方法:register_chrdev_region(dev_t first,unsigned int count,char *name) 
参数解释:First :要分配的设备编号范围的初始值(次设备号常设为0); 
	 Count:连续编号范围. 
         Name:编号相关联的设备名称. (/proc/devices); 
返回值:无

8.
头文件: #include linux/slab.h> 
函数名称: kmalloc
功能: 申请内存空间且并对其分配的内存不进行初始化（清零）,
      分配的区仍然持有它原来的内容。
使用方法:kmalloc(sizeof(struct mydev),GFP_KERNEL);
参数解释:第一个参数sizeof(struct mydev)是要分配的大小。
返回值:返回一个你分配的东西的内容。
9.
头文件:#include<linux/slab.h>
函数名称:kfree
功能:对kmalloc申请的内存空间进行释放。
使用方法:kfree(mydev->data);
参数解释:mydev->data是要释放的内存空间的地址
返回值:无
10.
头文件:#include<linux/fs.h>
函数名称:container_of
功能:据结构体中成员变量中某个成员的首地址来获取该结构体的首地址。
使用方法:container_of(ptr, type, member)
参数解释:
其中 ptr是指向type结构体成员变量中正被使用的某个成员变量的指针（即首地址）；type是包含ptr指向的成员变量的结构体；member是type结构体中的成员，类型与ptr指向的变量类型一样。
返回值:返回一个指针去存储返回的地址。
11.
头文件:#include<asm/uaccess.h>
函数名称:copy_to_user
功能:函数copy_to_user()完成用户空间到内核空间的复制。
使用方法:copy_to_user(void __user *to, const void *from, unsigned long n)
参数解释:
	To 目标地址，这个地址是用户空间的地址;
        From 源地址，这个地址是内核空间的地址;
        N 将要拷贝的数据的字节数。
返回值:无
12.
头文件:#include<asm/uaccess.h>
函数名称:copy_from_user
功能:函数copy_from_user()完成内核空间到用户空间的复制。
使用方法:copy_from_user(void *to, const void __user *from, unsigned long n)
参数解释:
	To 目标地址，这个地址是用户空间的地址;
        From 源地址，这个地址是内核空间的地址;
        N 将要拷贝的数据的字节数。
返回值:无
