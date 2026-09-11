# Subsystem: root

## app.py
- Layer: utility
- Doc: _*_ coding: utf8 _*_
- Language: py

## install.sh
- Layer: utility
- Language: sh

## lima_h3_emuna.c
- Layer: utility
- Doc: SPDX-License-Identifier: GPL-2.0-or-later
- Language: c
- Symbols:
  - `emuna_show` (function, line 44) `static ssize_t emuna_show(struct device *dev,
                          struct device_attribute *...`
  - `emuna_store` (function, line 59) `static ssize_t emuna_store(struct device *dev,
                           struct device_attribute...`
  - `emuna_init` (function, line 87) `static int __init emuna_init(void)`
  - `emuna_exit` (function, line 124) `static void __exit emuna_exit(void)`
  - `sysfs_emit` (function, line 49) `return sysfs_emit(buf, "MODE 0 (Cool): %u MHz\n" "MODE 1 (Warm): %u MHz\n" "MODE 2 (Hot): %u MHz\n" "MODE 3 (Critical): %u MHz\n", thermal_table_ptr[0], thermal_table_ptr[1], thermal_table_ptr[2], the`
  - `pr_info` (function, line 71) `pr_info(DRIVER_NAME ": Mode %u set to %u MHz (live)\n", mode, freq);`
  - `DEVICE_ATTR_RW` (function, line 74) `static DEVICE_ATTR_RW(emuna);`
  - `pr_err` (function, line 98) `pr_err(DRIVER_NAME ": thermal_ctrl_freq not found (mali.ko loaded?)\n");`
  - `pr_warn` (function, line 111) `pr_warn(DRIVER_NAME ": Unexpected critical freq %u MHz\n", thermal_table_ptr[3]);`
  - `sysfs_create_group` (function, line 122) `return sysfs_create_group(kernel_kobj, &emuna_group);`
  - `sysfs_remove_group` (function, line 135) `sysfs_remove_group(kernel_kobj, &emuna_group);`
  - `module_init` (function, line 139) `module_init(emuna_init);`
  - `MODULE_LICENSE` (function, line 142) `MODULE_LICENSE("GPL v2");`
  - `DRIVER_NAME` (macro, line 30) `#define DRIVER_NAME`
  - `THERMAL_TABLE_SIZE` (macro, line 32) `#define THERMAL_TABLE_SIZE`

## patch_thermal.c
- Layer: utility
- Doc: include <linux/module.h> include <linux/kernel.h>  Parchear thermal_ctrl_freq en la dirección 0x294e4
- Language: c
- Symbols:
  - `thermal_patch_init` (function, line 6) `static int __init thermal_patch_init(void)`
  - `printk` (function, line 13) `printk(KERN_INFO "Mali thermal throttle patched\n");`
  - `module_init` (function, line 17) `module_init(thermal_patch_init);`
  - `thermal_ctrl_freq` (variable, line 5) `extern uint32_t thermal_ctrl_freq[];`
