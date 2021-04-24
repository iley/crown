MCU=atmega328p
FREQ=8000000UL

DOCKER_IMAGE=istrukov/avr-tools
DOCKER_RUN=docker run --rm -t -v $(PWD):/workspace -w /workspace $(DOCKER_IMAGE)
CC=$(DOCKER_RUN) avr-gcc
OBJCOPY=$(DOCKER_RUN) avr-objcopy
AVR_SIZE=$(DOCKER_RUN) avr-size

default: firmware.hex size

OBJ=main.o programs.o

$(OBJ): %.o: %.c
	$(CC) -c -g -Os -mmcu=$(MCU) -DF_CPU=$(FREQ) -o $@ $<

firmware.elf: $(OBJ)
	$(CC) -g -mmcu=$(MCU) -o $@ $^

firmware.hex: firmware.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

program: firmware.hex
	minipro -p $(MCU) -f ihex -w $<
	minipro -p $(MCU) -c config -w fuses.txt

fuses:
	minipro -p $(MCU) -c config -w fuses.txt

size: firmware.elf
	$(AVR_SIZE) $<

clean:
	rm -f $(OBJ) firmware.elf firmware.hex

docker: .docker-image

.docker-image: Dockerfile
	docker build . -t $(DOCKER_IMAGE)
	touch $@

.PHONY: default docker program clean size fuses
