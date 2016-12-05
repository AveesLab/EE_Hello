flash: build
	avrdude -C"$(AVR_TOOLS)/etc/avrdude.conf" -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:Debug/arduino.hex:i
	
build:
	cd Debug; make
	
clean:
	cd Debug; make clean
