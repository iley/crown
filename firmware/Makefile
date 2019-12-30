MCU=atmega328p
FREQ=8000000UL

default: firmware.hex size

OBJ=main.o programs.o

${OBJ}: %.o: %.c
	avr-gcc -c -g -Os -mmcu=${MCU} -DF_CPU=${FREQ} -o $@ $^

firmware.elf: ${OBJ}
	avr-gcc -g -mmcu=${MCU} -o $@ $^

firmware.hex: firmware.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

program: firmware.hex
	minipro -p ${MCU} -f ihex -w $<
	minipro -p ${MCU} -c config -w fuses.txt

fuses:
	minipro -p ${MCU} -c config -w fuses.txt

size: firmware.elf
	avr-size --mcu=${MCU} -C $<

clean:
	rm -f ${OBJ} firmware.elf firmware.hex

.PHONY: default program clean size fuses
