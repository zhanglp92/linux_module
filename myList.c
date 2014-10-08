/*************************************************************************
	> File Name: myList.c
	> Author: zhanglp
	> Mail: ql.zhanglp@qq.com
	> Created Time: 2014年09月22日 星期一 10时40分11秒
 ************************************************************************/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>

struct numList {

    int     num;
    struct list_head list;
};

#define N   10

// 链表头节点
struct numList numHead; 

static void findList (const struct numList *head);

static void findList (const struct numList *head)
{
    struct list_head *pos;
    struct numList *p;
    int i = 1;

    // 顺序向后遍历
    list_for_each (pos, &head->list) {

        // 通过节点的指针域，找到该节点的起始位置
        p = list_entry (pos, struct numList, list);
        printk ("Node %d's data: %d \n", i++, p->num);
    }
}

static int __init myList_init (void)
{
    struct numList *listNode; 
    int     i;

    printk ("doublelist is starting... \n"); 

    // 初始化链表头节点
    INIT_LIST_HEAD (&numHead.list);
    for (i = 0; i < N; i++) {
    
        /* 用kmalloc 申请空间
         * 内核中开辟内存kmalloc ,vmalloc，或者get_free_pages 直接申请页
         * 向对应的释放 kfree,vfree，或free_pages
         * kmalloc 分配的内存是物理上连续的
         * vmalloc 分配的内存只是线性地址连续, 物理地址不一定连续
         *
         * kmalloc vmalloc 申请空间时，各自到自己对应的特殊区域申请
         * kmalloc 最多只能开辟大小为32XPAGE_SIZE 的内存
         */
        listNode = kmalloc (sizeof (struct numList), GFP_KERNEL); 
        listNode->num = i+1;

        // 链表的头插
        list_add (&listNode->list, &numHead.list);

        listNode = kmalloc (sizeof (struct numList), GFP_KERNEL); 
        listNode->num = -(i+1);
        // 链表的尾插
        list_add_tail (&listNode->list, &numHead.list);
    }
    
    findList (&numHead);

    return 0;
}

static void __exit myList_exit (void)
{
    struct list_head *n, *pos;
    struct numList *p;

    /* 在释放节点时，必须得使用 list_for_each_safe
     * 用n 可以指向删除节点的下一个节点
     *
     * 若使用 list_for_each 
     * 当节点释放就不能找到下一个节点
     */
    list_for_each_safe (pos, n, &numHead.list) {
        
        list_del (pos);
        p = list_entry (pos, struct numList, list);
        kfree (p);
    }
}

module_init (myList_init);
module_exit (myList_exit);
MODULE_LICENSE ("GPL");
