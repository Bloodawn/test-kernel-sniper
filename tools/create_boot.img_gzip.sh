#!/bin/bash
# Kernel packer for LG Marquee by Bloodawn

if test -e zImage
then
    ./mkbootimg --kernel zImage --ramdisk ramdisk.cpio.gz --cmdline " console=ttyMSM1 androidboot.hardware=qcom" -o  boot.img --base 0x80000000
    cp /home/ss/kernel/jb/tools/boot.img ../done/.
    rm /home/ss/kernel/jb/tools/boot.img  
else
    echo "No zImage found"
fi

