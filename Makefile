# Makefile 0.1

obj-m 	:= myList.o
LINUX_KENEL_PATH 	:= /usr/src/linux-headers-$(shell uname -r)

all:
	make -C $(LINUX_KENEL_PATH) M=$(shell pwd) modules

clean:
	make -C $(LINUX_KENEL_PATH) M=$(shell pwd) clean
