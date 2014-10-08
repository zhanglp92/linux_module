/*************************************************************************
	> File Name: print_pid.c
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月20日 星期四 21时19分56秒
 ************************************************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>

static int print_pid (void)
{
    struct task_struct  *task, *p;
    struct list_head    *pos;
    int     cnt = 0;

    task = current;
//    task = &init_task; 
    list_for_each (pos, &task->tasks) {
        p = list_entry (pos, struct task_struct, tasks);
        cnt++;
        printk ("%d-----> %s\n", p->pid, p->comm);
    }
    printk ("the number of process is : %d\n", cnt);

    return 0;
}

static int __init print_init (void)
{
    printk ("Hello World enter begin!\n");

    return print_pid ();
}

static void __exit print_exit (void)
{
    printk ("Hello World enter end!\n");
}

module_init (print_init);
module_exit (print_exit);
MODULE_LICENSE ("GPL");
