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
  - `DRIVER_NAME` (macro, line 30)
  - `THERMAL_TABLE_SIZE` (macro, line 32)

## patch_thermal.c
- Layer: utility
- Doc: include <linux/module.h> include <linux/kernel.h>  Parchear thermal_ctrl_freq en la dirección 0x294e4
- Language: c
- Symbols:
  - `thermal_patch_init` (function, line 6) `static int __init thermal_patch_init(void)`
