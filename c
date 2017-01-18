#!/bin/sh

make build

if [ $? -eq 0 ]
then
    make flash
        if [ $? -eq 0 ]
        then
            miniterm.py /dev/cu.usbmodem1411 9600
        fi
fi

