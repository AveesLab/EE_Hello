# For Windows
EE_DIR=C:\eclipse
GENERATOR=$(EE_DIR)\evidence\generate_code.bat
COM_DEVICE=COM3

# For Mac OS
#EE_DIR=/Users/jongchank/EE_RT-Druid-2.7.0-juno-macosx-cocoa-x86_64/eclipse
#GENERATOR=$(EE_DIR)/evidence/generate_code.sh
#COM_DEVICE=/dev/cu.usbmodem1411

BUILD_DIR=Debug
CONF_FILE=$(AVR_TOOLS)/etc/avrdude.conf
BAUDRATE=115200
HEX_FILE=$(BUILD_DIR)/arduino.hex

all: config build flash 

flash: build
	avrdude -C"$(CONF_FILE)" -v -patmega328p -carduino -P$(COM_DEVICE) -b$(BAUDRATE) -D -Uflash:w:$(HEX_FILE):i

build:
	cd $(BUILD_DIR); make

config: conf.oil
	$(GENERATOR) $(EE_DIR) conf.oil $(BUILD_DIR)

clean:
	cd $(BUILD_DIR); make clean
