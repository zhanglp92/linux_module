/*************************************************************************
	> File Name: test.c
	> Author: zhanglp
	> Mail: 820221185@qq.com
	> Created Time: 2014年03月12日 星期三 17时14分00秒
 ************************************************************************/

#include <stdio.h>


#define MODULE_LICENSE(_license) MODULE_INFO(license, _license)
#define MODULE_INFO(tag, info) __MODULE_INFO(tag, tag, info)

#define ___module_cat(a,b) __mod_ ## a ## b 
#define __module_cat(a,b) ___module_cat(a,b)
#define __MODULE_INFO(tag, name, info) \
    static const char __module_cat(name,__LINE__)[] \
    __attribute_used__  \
    __attribute__((section(".modinfo"),unused)) = __stringify(tag) "=" info

#define __stringify_1(x)    #x
#define __stringify(x)        __stringify_1(x)


/*
static const char 
    __mod_license24[] __attribute__ ((__used__)) 
    __attribute__((section(".modinfo"),unused)) = "GPL"; 
*/

void funab(void) 
{
    printf ("haha :\n");
}

#define can(x)     x 


#define fun(a, b) \
    fun ## a ## b () 

MODULE_LICENSE("GPL"); 
int main (void)
{
    static const char __mod_license16[]= "license" "=" "Dual BSD/GPL";
    puts (__mod_license16);

    fun(a, b);

    return 0;
}
