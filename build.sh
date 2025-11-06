#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
KERNELDIR="${KERNELDIR:-/home/grisun0/kernel/orange-pi-6.6}"
CROSS="${CROSS_COMPILE:-arm-linux-gnueabihf-}"

echo "[EVIDENCIA] Verificando cross-compiler..."
command -v ${CROSS}gcc >/dev/null || {
    echo "❌ Instala: sudo apt install gcc-arm-linux-gnueabihf"
    exit 1
}

echo "[EVIDENCIA] Verificando kernel ARM32..."
[[ -f "$KERNELDIR/arch/arm/Makefile" ]] || {
    echo "❌ Clona el kernel ARM32 para H3:"
    echo "   git clone --depth 1 -b v6.6 https://github.com/orangepi-xunlong/linux-orangepi.git $KERNELDIR"
    exit 1
}

echo "[COMPILANDO] lima_h3_emuna.ko para ARM32..."
make -C "$KERNELDIR" ARCH=arm CROSS_COMPILE="$CROSS" M="$SCRIPT_DIR" modules

echo "[✓] Objeto generado: $SCRIPT_DIR/lima_h3_emuna.ko"
file "$SCRIPT_DIR/lima_h3_emuna.ko"

echo "[INFO] Para instalar en H3:"
echo "   scp lima_h3_emuna.ko orangepi@<ip>:/tmp/"
echo "   ssh orangepi 'sudo insmod /tmp/lima_h3_emuna.ko'"