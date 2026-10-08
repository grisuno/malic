# root

*Community 0 | 4 files | cohesion 1.00*

## Definition

This community groups 4 file(s) rooted at `root` with dominant language c (cohesion 1.00). Central symbols: `DEVICE_ATTR_RW`, `DRIVER_NAME`, `THERMAL_TABLE_SIZE`, `emuna_exit`, `emuna_init`, `emuna_show`, `emuna_store`, `thermal_ctrl_freq`. Core file: `lima_h3_emuna.c` (7 symbols). Documented purpose: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:.

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `app.py` | py | utility | 0 | yes |
| `install.sh` | sh | utility | 0 | no |
| `lima_h3_emuna.c` | c | utility | 7 | yes |
| `patch_thermal.c` | c | utility | 2 | yes |

## Key Symbols

- `DRIVER_NAME` (macro, `lima_h3_emuna.c:31`) `#define DRIVER_NAME`
- `THERMAL_TABLE_SIZE` (macro, `lima_h3_emuna.c:32`) `#define THERMAL_TABLE_SIZE`
- `emuna_show` (function, `lima_h3_emuna.c:45`) `static ssize_t emuna_show(struct device *dev,                           struct d`
- `emuna_store` (function, `lima_h3_emuna.c:60`) `static ssize_t emuna_store(struct device *dev,                            struct`
- `DEVICE_ATTR_RW` (function, `lima_h3_emuna.c:75`) `static DEVICE_ATTR_RW(emuna);`
- `emuna_init` (function, `lima_h3_emuna.c:88`) `static int __init emuna_init(void)`
- `emuna_exit` (function, `lima_h3_emuna.c:125`) `static void __exit emuna_exit(void)`
- `thermal_ctrl_freq` (variable, `patch_thermal.c:5`) `extern uint32_t thermal_ctrl_freq[];` - #include <linux/module.h> #include <linux/kernel.h> /* Parchear thermal_ctrl_freq en la dirección 0x
- `thermal_patch_init` (function, `patch_thermal.c:7`) `static int __init thermal_patch_init(void)`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 0
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- No cross-community bridges recorded. This community is self-contained.

## Risks

- No scoped security, taint, cycle, or layer risks.

## Open Questions

- Why do 1 file(s) lack file-level docs (e.g. `install.sh`)? What purpose do they serve?
- What would break if the most connected file in root changed?
- Should root be split, given cohesion 1.00?

## Sources

- `app.py`
- `install.sh`
- `lima_h3_emuna.c`
- `patch_thermal.c`
