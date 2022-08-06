C_SOURCES = $(wildcard kernel/*.c drivers/*.c drivers/ata/*.c cpu/*.c libc/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h drivers/ata/*.h cpu/*.h libc/*.h)

# Nice syntax for file extension replacement
OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o kernel/switch.o}

# Change this if your cross-compiler is somewhere else
CC = gcc

# -g: Use debugging symbols in gcc
CFLAGS = -g -ffreestanding -Wall -Wextra -fno-exceptions -m32 -fno-pie

# First rule is run by default
profanOS.bin: boot/bootsect.bin kernel.bin hdd.bin
	cat boot/bootsect.bin kernel.bin > profanOS.bin

# some variables to build the ISO.

FILESIZE = $(shell stat -c%s "profanOS.bin")
SECTORSIZE = 512
DIVIDED = $(shell echo $$(($(FILESIZE) / $(SECTORSIZE))))
FLOPPYSECS = 2876
FILLERSIZE = $(shell echo $$(($(FLOPPYSECS) - $(DIVIDED))))


iso: profanOS.bin
	mkdir -p iso
	$(info Filesize: $(FILESIZE), No. of sectors: $(DIVIDED))
	dd if="/dev/zero" bs=$(SECTORSIZE) count=$(FILLERSIZE) of="iso/_filler.img"
	$(info Filler created.)
	cat profanOS.bin iso/_filler.img > iso/_floppy.img
	$(info Secondary image created.)
	touch iso/_floppy.catalog
	mkisofs -input-charset iso8859-1 -r -b "iso/_floppy.img" -c "iso/_floppy.catalog" -o "profanOS.iso" .


# '--oformat binary' deletes all symbols as a collateral, so we don't need
# to 'strip' them manually on this case
kernel.bin: boot/kernel_entry.o ${OBJ}
	ld -m elf_i386 -G -o $@ -Ttext 0x1000 $^ --oformat binary

# create a 1MB hdd.bin file
hdd.bin:
	dd if=/dev/zero of=hdd.bin bs=1024 count=1024

run: profanOS.bin hdd.bin
	qemu-system-i386 -drive file=profanOS.bin,if=floppy,format=raw -drive file=hdd.bin,format=raw -boot order=a

iso_run: iso
	qemu-system-i386 -cdrom profanOS.iso -boot order=d

# Generic rules for wildcards
# To make an object, always compile from its .c
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf kernel.bin *.dis *.o *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o drivers/ata/*.o boot/*.o cpu/*.o libc/*.o

fullclean: clean
	rm -rf *.bin *.iso ./iso
