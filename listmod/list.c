/*************************************************************************
	> File Name: list.c
	> Author: zhanglp
	> Mail: 820221185@qq.com 
	> Created Time: 2014年03月12日 星期三 20时42分10秒
 ************************************************************************/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/list.h>


#define N   10 
struct numlist {
    int     num;
    struct list_head list;
};

struct numlist  numhead;

static int doblelist_init (void)
{
    int     i;
    struct numlist      *listnode;
    struct list_head    *pos; 

    printk ("doublelist is starting...\n");
    INIT_LIST_HEAD (&numhead.list);

    for (i = 0; i < N; i++) {
        listnode = (struct numlist *)kmalloc (sizeof (struct numlist), GFP_KERNEL);
        listnode->num = i+1;
        list_add_tail (&listnode->list, &numhead.list);
        printk ("Node %d has added to the doublelist...\n", i+1);
    }

    i = 1;
    list_for_each (pos, &numhead.list) {
        listnode = list_entry (pos, struct numlist, list);
        printk ("Node %d's data: %d\n", i++, listnode->num);
    }

    return 0;
}

static void doblelist_exit (void)
{
    int     i = 1;
    struct list_head    *pos, *n;
    struct numlist      *p;
    list_for_each_safe (pos, n, &numhead.list) {
        list_del (pos);
        p = list_entry (pos, struct numlist, list);
        kfree (p);
        printk ("Node %d has removed from the doublelist...\n", i++);
    }
    printk ("doublelist is exiting...\n");
}

module_init (doblelist_init);
module_exit (doblelist_exit);
