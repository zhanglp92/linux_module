# Makefile0.1

obj-m := list.o

CURRENT_PATH := $(shell pwd)
LINUX_KERNEL_PATH := /usr/src/linux-headers-$(shell uname -r)

all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules

clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
