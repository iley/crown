MCU=atmega328p
FREQ=8000000UL

default: firmware.hex size

firmware.o: main.c
	avr-gcc -g -Os -mmcu=${MCU} -DF_CPU=${FREQ} -o $@ -c $^

firmware.elf: firmware.o
	avr-gcc -g -mmcu=${MCU} -o $@ $^

firmware.hex: firmware.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

program: firmware.hex
	minipro -p ${MCU} -f ihex -w $<

size: firmware.elf
	avr-size --mcu=${MCU} -C $<

clean:
	rm -f firmware.o firmware.elf firmware.hex

.PHONY: default program clean size
