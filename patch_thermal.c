#include <linux/module.h>
#include <linux/kernel.h>

/* Parchear thermal_ctrl_freq en la dirección 0x294e4 */
extern uint32_t thermal_ctrl_freq[];

static int __init thermal_patch_init(void) {
    // Aumentar frecuencias mínimas
    thermal_ctrl_freq[0] = 400;  // Mode 0: 576 → 400 MHz
    thermal_ctrl_freq[1] = 350;  // Mode 1: 432 → 350 MHz
    thermal_ctrl_freq[2] = 280;  // Mode 2: 312 → 280 MHz
    thermal_ctrl_freq[3] = 200;  // Mode 3: 120 → 200 MHz (CRÍTICO)
    
    printk(KERN_INFO "Mali thermal throttle patched\n");
    return 0;
}

module_init(thermal_patch_init);
MODULE_LICENSE("GPL");
