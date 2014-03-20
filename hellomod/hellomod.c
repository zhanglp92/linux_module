/*************************************************************************
	> File Name: hellomod.c
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月11日 星期二 17时30分15秒
 ************************************************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init lkp_init (void)
{
    printk ("<1> Hello, world! from the kernel space...\n");
    return 0;
}

static void __exit  lkp_exit (void)
{
    printk ("<1> Goodbye, world! leaving kernel space...\n");
}

module_init (lkp_init);
module_exit (lkp_exit);
MODULE_LICENSE ("GPL");
