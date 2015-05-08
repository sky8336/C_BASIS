#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
#include <linux/fs.h>
//#include <linux/kdev_t.h>
MODULE_LICENSE("GPL");

static int global_data = 123;
EXPORT_SYMBOL(global_data);

int print_k(void)
{
	printk("hello_v1.c --->fun_called ok !!: defined in hello.c\n");
}
EXPORT_SYMBOL(print_k);

int *funp(void)
{
	int *fun_p;
	fun_p = &global_data;
	printk("fun_p called\n");
	return fun_p;
}
EXPORT_SYMBOL(funp);

int devmax = 250;
int devmix = 0; 

int hello_init(void)
{
	dev_t devno = MKDEV(devmax,devmix);
	register_chrdev_region(devno,1,"hello");

	printk("init_module\n");
	return 0;
}

void hello_exit(void)
{

	dev_t devno = MKDEV(devmax,devmix);
	unregister_chrdev_region(devno,1);
	printk("cleanup_module\n");	
	
}

module_init(hello_init);
module_exit(hello_exit);



