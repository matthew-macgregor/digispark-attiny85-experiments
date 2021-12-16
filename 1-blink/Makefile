# Depends:
# gcc-avr avr-libc ?

DEVICE  = attiny85
CLOCK   = 16000000	# 16mhz
OBJ	= main.o

# Make sure micronucleus is in PATH or change LOADER
LOADER  = micronucleus
GCC	= avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)  

.PHONY: clean all

all: main.hex

.c.o:
	$(GCC) -c $< -o $@

flash: all
	$(LOADER) --run main.hex

clean:
	rm -f main.hex main.elf $(OBJ)


main.elf: $(OBJ)
	$(GCC) -o main.elf $(OBJ)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(DEVICE) main.elf
