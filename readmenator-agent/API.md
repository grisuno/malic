# API

## lima_h3_emuna.c

### emuna_show `static ssize_t emuna_show(struct device *dev,
                          struct device_attribute *...`
- Defined: `lima_h3_emuna.c:44`
- Doc: #define DRIVER_NAME "lima_h3_emuna" #define THERMAL_TABLE_SIZE 4 /* Original values found in mali.ko @ 0x194f4 static co

### emuna_store `static ssize_t emuna_store(struct device *dev,
                           struct device_attribute...`
- Defined: `lima_h3_emuna.c:59`

### emuna_init `static int __init emuna_init(void)`
- Defined: `lima_h3_emuna.c:87`
- Doc: } static DEVICE_ATTR_RW(emuna); static struct attribute *emuna_attrs[] = { &dev_attr_emuna.attr, NULL }; static const st

### emuna_exit `static void __exit emuna_exit(void)`
- Defined: `lima_h3_emuna.c:124`

## patch_thermal.c

### thermal_patch_init `static int __init thermal_patch_init(void)`
- Defined: `patch_thermal.c:6`
