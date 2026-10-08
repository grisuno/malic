# Subsystem: root

## app.py
- Doc: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación...
- Layer: utility
- Language: py

## install.sh
- Layer: utility
- Language: sh

## lima_h3_emuna.c
- Layer: utility
- Language: c
- Symbols:
  - `emuna_show` (function, line 45) `static ssize_t emuna_show(struct device *dev,
                          struct device_attribute *...`
  - `emuna_store` (function, line 60) `static ssize_t emuna_store(struct device *dev,
                           struct device_attribute...`
  - `emuna_init` (function, line 88) `static int __init emuna_init(void)`
  - `emuna_exit` (function, line 125) `static void __exit emuna_exit(void)`
  - `DEVICE_ATTR_RW` (function, line 75) `static DEVICE_ATTR_RW(emuna);`
  - `DRIVER_NAME` (macro, line 31) `#define DRIVER_NAME`
  - `THERMAL_TABLE_SIZE` (macro, line 32) `#define THERMAL_TABLE_SIZE`

## patch_thermal.c
- Doc: Parchear thermal_ctrl_freq en la dirección 0x294e4
- Layer: utility
- Language: c
- Symbols:
  - `thermal_patch_init` (function, line 7) `static int __init thermal_patch_init(void)`
  - `thermal_ctrl_freq` (variable, line 5) `extern uint32_t thermal_ctrl_freq[];`
