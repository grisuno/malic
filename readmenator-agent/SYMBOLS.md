# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `DEVICE_ATTR_RW` | function | `lima_h3_emuna.c:74` | `static DEVICE_ATTR_RW(emuna);` |
| `DRIVER_NAME` | macro | `lima_h3_emuna.c:30` | `#define DRIVER_NAME` |
| `MODULE_LICENSE` | function | `lima_h3_emuna.c:142` | `MODULE_LICENSE("GPL v2");` |
| `THERMAL_TABLE_SIZE` | macro | `lima_h3_emuna.c:32` | `#define THERMAL_TABLE_SIZE` |
| `emuna_exit` | function | `lima_h3_emuna.c:124` | `static void __exit emuna_exit(void)` |
| `emuna_init` | function | `lima_h3_emuna.c:87` | `static int __init emuna_init(void)` |
| `emuna_show` | function | `lima_h3_emuna.c:44` | `static ssize_t emuna_show(struct device *dev,
                          struct device_attribute *...` |
| `emuna_store` | function | `lima_h3_emuna.c:59` | `static ssize_t emuna_store(struct device *dev,
                           struct device_attribute...` |
| `module_init` | function | `lima_h3_emuna.c:139` | `module_init(emuna_init);` |
| `pr_err` | function | `lima_h3_emuna.c:98` | `pr_err(DRIVER_NAME ": thermal_ctrl_freq not found (mali.ko loaded?)\n");` |
| `pr_info` | function | `lima_h3_emuna.c:71` | `pr_info(DRIVER_NAME ": Mode %u set to %u MHz (live)\n", mode, freq);` |
| `pr_warn` | function | `lima_h3_emuna.c:111` | `pr_warn(DRIVER_NAME ": Unexpected critical freq %u MHz\n", thermal_table_ptr[3]);` |
| `sysfs_create_group` | function | `lima_h3_emuna.c:122` | `return sysfs_create_group(kernel_kobj, &emuna_group);` |
| `sysfs_emit` | function | `lima_h3_emuna.c:49` | `return sysfs_emit(buf, "MODE 0 (Cool): %u MHz\n" "MODE 1 (Warm): %u MHz\n" "MODE 2 (Hot): %u MHz\n" "MODE 3 (Critical): ` |
| `sysfs_remove_group` | function | `lima_h3_emuna.c:135` | `sysfs_remove_group(kernel_kobj, &emuna_group);` |
| `module_init` | function | `patch_thermal.c:17` | `module_init(thermal_patch_init);` |
| `printk` | function | `patch_thermal.c:13` | `printk(KERN_INFO "Mali thermal throttle patched\n");` |
| `thermal_ctrl_freq` | variable | `patch_thermal.c:5` | `extern uint32_t thermal_ctrl_freq[];` |
| `thermal_patch_init` | function | `patch_thermal.c:6` | `static int __init thermal_patch_init(void)` |
