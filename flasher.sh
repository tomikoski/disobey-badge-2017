#!/bin/bash

while [ 1 ]; do
	sudo avrdude -c usbasp -p ATmega328P -U lfuse:w:0x62:m -U efuse:w:0x7:m -U hfuse:w:0xd9:m -U flash:w:morse.hex
	sleep 1s
done