# API

## lima_h3_emuna.c

### emuna_show (function) `static ssize_t emuna_show(struct device *dev,
                          struct device_attribute *...`
- Defined: `lima_h3_emuna.c:44`
- Doc: #define DRIVER_NAME "lima_h3_emuna" #define THERMAL_TABLE_SIZE 4 /* Original values found in mali.ko @ 0x194f4 static co

### emuna_store (function) `static ssize_t emuna_store(struct device *dev,
                           struct device_attribute...`
- Defined: `lima_h3_emuna.c:59`

### emuna_init (function) `static int __init emuna_init(void)`
- Defined: `lima_h3_emuna.c:87`
- Doc: } static DEVICE_ATTR_RW(emuna); static struct attribute *emuna_attrs[] = { &dev_attr_emuna.attr, NULL }; static const st

### emuna_exit (function) `static void __exit emuna_exit(void)`
- Defined: `lima_h3_emuna.c:124`

### sysfs_emit (function) `return sysfs_emit(buf, "MODE 0 (Cool): %u MHz\n" "MODE 1 (Warm): %u MHz\n" "MODE 2 (Hot): %u MHz\n" "MODE 3 (Critical): %u MHz\n", thermal_table_ptr[0], thermal_table_ptr[1], thermal_table_ptr[2], the`
- Defined: `lima_h3_emuna.c:49`

### pr_info (function) `pr_info(DRIVER_NAME ": Mode %u set to %u MHz (live)\n", mode, freq);`
- Defined: `lima_h3_emuna.c:71`

### DEVICE_ATTR_RW (function) `static DEVICE_ATTR_RW(emuna);`
- Defined: `lima_h3_emuna.c:74`

### pr_err (function) `pr_err(DRIVER_NAME ": thermal_ctrl_freq not found (mali.ko loaded?)\n");`
- Defined: `lima_h3_emuna.c:98`

### pr_warn (function) `pr_warn(DRIVER_NAME ": Unexpected critical freq %u MHz\n", thermal_table_ptr[3]);`
- Defined: `lima_h3_emuna.c:111`

### sysfs_create_group (function) `return sysfs_create_group(kernel_kobj, &emuna_group);`
- Defined: `lima_h3_emuna.c:122`
- Doc: if (thermal_table_ptr[3] == 120) { pr_info(DRIVER_NAME ": Confirmed stock throttle (120 MHz critical)\n"); } else { pr_w

### sysfs_remove_group (function) `sysfs_remove_group(kernel_kobj, &emuna_group);`
- Defined: `lima_h3_emuna.c:135`

### module_init (function) `module_init(emuna_init);`
- Defined: `lima_h3_emuna.c:139`

### MODULE_LICENSE (function) `MODULE_LICENSE("GPL v2");`
- Defined: `lima_h3_emuna.c:142`

## patch_thermal.c

### thermal_patch_init (function) `static int __init thermal_patch_init(void)`
- Defined: `patch_thermal.c:6`

### printk (function) `printk(KERN_INFO "Mali thermal throttle patched\n");`
- Defined: `patch_thermal.c:13`

### module_init (function) `module_init(thermal_patch_init);`
- Defined: `patch_thermal.c:17`
