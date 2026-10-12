# CalculatorOS
A fork of [WarblerOS]([url](https://github.com/Calculuxe/WarblerOS)) that is stripped down to the calculator. It also has some unique features that are helpful for calculstors.

## What is CalculatorOS?
CalculatorOS is another little hobby project operating system I have been doing for a few days. I made it because I'm tired of the monopoly that Microsoft has on the OS market even though they are highly unethical.
So, I made CalculatorOS to prove some independence. It doesn't do too much, but feel free to fork this repository and add whatever you want to your fork. It would also be nice if I got suggestions! I'm really new to this stuff.

## How do I install CalculatorOS?
Just go to the releases and download the iso file and put it into any hypervisor. If you want to compile from the source, I did it on a mac, so you need i686-elf-gcc, i686-elf, i686-elf-ld / binutils, nasm, i686-elf-grub-mkrescue, make, and xorriso. Once you have those installed, go to the folder that the code is in and type "make clean && make". It should output an iso.
