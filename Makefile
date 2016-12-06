EE_DIR=C:\eclipse
GENERATOR=$(EE_DIR)\evidence\generate_code.bat
BUILD_DIR=Debug
CONF_FILE=$(AVR_TOOLS)/etc/avrdude.conf
COM_DEVICE=COM3
BAUDRATE=115200
HEX_FILE=$(BUILD_DIR)/arduino.hex

flash: build
	avrdude -C"$(CONF_FILE)" -v -patmega328p -carduino -P$(COM_DEVICE) -b$(BAUDRATE) -D -Uflash:w:$(HEX_FILE):i
	
build:
	cd $(BUILD_DIR); make

config: conf.oil
	$(GENERATOR) $(EE_DIR) conf.oil $(BUILD_DIR)

clean:
	cd $(BUILD_DIR); make clean
