// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * lima_h3_emuna.ko - Mali-400 Thermal Override for Orange Pi H3
 *
 * Copyright (C) 2025 – grisuno (LazyOwn Project)
 *
 * This module **overrides the hardcoded thermal throttle table**
 * found in the **closed-source mali.ko** at offset **0x194f4**.
 *
 * Evidence:
 * - Reverse-engineered from mali.ko (3.4.113-orangepi)
 * - Confirmed thermal_ctrl_freq[] = [576, 432, 312, 120] MHz
 * - 120 MHz causes CMA starvation and Lima framebuffer stalls
 *
 * Mission:
 * - Never let the GPU drop below 200 MHz
 * - Preserve CMA coherency under thermal stress
 * - Expose sysfs interface for live tuning
 *
 * “La Emuna no se throttlea”
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>
#include <linux/sysfs.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>

#define DRIVER_NAME "lima_h3_emuna"
#define THERMAL_TABLE_SIZE 4

/* Original values found in mali.ko @ 0x194f4 */
static const u32 original_freqs[THERMAL_TABLE_SIZE] = {576, 432, 312, 120};

/* Emuna values: never below 200 MHz */
static const u32 emuna_freqs[THERMAL_TABLE_SIZE]     = {400, 350, 280, 200};

static u32 *thermal_table_ptr = NULL;
static u32  backup_table[THERMAL_TABLE_SIZE];

/* ========== SYSFS: Live Tuning ========== */

static ssize_t emuna_show(struct device *dev,
                          struct device_attribute *attr,
                          char *buf)
{
    return sysfs_emit(buf,
        "MODE 0 (Cool):     %u MHz\n"
        "MODE 1 (Warm):     %u MHz\n"
        "MODE 2 (Hot):      %u MHz\n"
        "MODE 3 (Critical): %u MHz\n",
        thermal_table_ptr[0],
        thermal_table_ptr[1],
        thermal_table_ptr[2],
        thermal_table_ptr[3]);
}

static ssize_t emuna_store(struct device *dev,
                           struct device_attribute *attr,
                           const char *buf, size_t count)
{
    u32 mode, freq;
    if (sscanf(buf, "%u %u", &mode, &freq) != 2)
        return -EINVAL;
    if (mode >= THERMAL_TABLE_SIZE || freq < 200 || freq > 600)
        return -EINVAL;

    thermal_table_ptr[mode] = freq;
    pr_info(DRIVER_NAME ": Mode %u set to %u MHz (live)\n", mode, freq);
    return count;
}

static DEVICE_ATTR_RW(emuna);

static struct attribute *emuna_attrs[] = {
    &dev_attr_emuna.attr,
    NULL
};

static const struct attribute_group emuna_group = {
    .attrs = emuna_attrs,
};

/* ========== Core Logic ========== */

static int __init emuna_init(void)
{
    unsigned long addr;
    int i;

    pr_info(DRIVER_NAME ": Initializing Mali H3 Emuna override\n");

    /* 1. Locate thermal_ctrl_freq in mali.ko */
    addr = kallsyms_lookup_name("thermal_ctrl_freq");
    if (!addr) {
        pr_err(DRIVER_NAME ": thermal_ctrl_freq not found (mali.ko loaded?)\n");
        return -ENOENT;
    }
    thermal_table_ptr = (u32 *)addr;

    /* 2. Backup original */
    for (i = 0; i < THERMAL_TABLE_SIZE; i++)
        backup_table[i] = thermal_table_ptr[i];

    /* 3. Validate */
    if (thermal_table_ptr[3] == 120) {
        pr_info(DRIVER_NAME ": Confirmed stock throttle (120 MHz critical)\n");
    } else {
        pr_warn(DRIVER_NAME ": Unexpected critical freq %u MHz\n",
                thermal_table_ptr[3]);
    }

    /* 4. Inject Emuna table */
    for (i = 0; i < THERMAL_TABLE_SIZE; i++)
        thermal_table_ptr[i] = emuna_freqs[i];

    pr_info(DRIVER_NAME ": Thermal table overridden – CMA-safe floor 200 MHz\n");

    /* 5. Export sysfs */
    return sysfs_create_group(kernel_kobj, &emuna_group);
}

static void __exit emuna_exit(void)
{
    int i;

    /* Restore original */
    if (thermal_table_ptr) {
        for (i = 0; i < THERMAL_TABLE_SIZE; i++)
            thermal_table_ptr[i] = backup_table[i];
        pr_info(DRIVER_NAME ": Original table restored\n");
    }

    sysfs_remove_group(kernel_kobj, &emuna_group);
    pr_info(DRIVER_NAME ": Unloaded\n");
}

module_init(emuna_init);
module_exit(emuna_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("grisuno <lazyown@ring-3.hell>");
MODULE_DESCRIPTION("Mali H3 Thermal Override – Emuna Edition");
MODULE_VERSION("1.0-emuna");