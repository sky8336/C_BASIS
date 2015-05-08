#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
MODULE_LICENSE("GPL");

static int global_data = 123;
EXPORT_SYMBOL(global_data);

int print_k(void)
{
	printk("hello_v1.c --->fun_called ok !!: defined in hello.c\n");
}
EXPORT_SYMBOL(print_k);

int hello_init(void)
{
	printk("init_module\n");
	return 0;
}

void hello_exit(void)
{
	printk("cleanup_module\n");	
	
}

module_init(hello_init);
module_exit(hello_exit);
