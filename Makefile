# SPDX-License-Identifier: GPL-2.0
# Makefile para lima_h3_emuna.ko
# Cross-compile para ARM32 (Orange Pi H3)

ARCH ?= arm
CROSS_COMPILE ?= arm-linux-gnueabihf-
KERNELDIR ?= /home/grisun0/kernel/orange-pi-6.6

obj-m += lima_h3_emuna.o

all:
	$(MAKE) -C $(KERNELDIR) \
		ARCH=$(ARCH) \
		CROSS_COMPILE=$(CROSS_COMPILE) \
		M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) \
		ARCH=$(ARCH) \
		CROSS_COMPILE=$(CROSS_COMPILE) \
		M=$(PWD) clean

install:
	sudo insmod lima_h3_emuna.ko

uninstall:
	sudo rmmod lima_h3_emuna