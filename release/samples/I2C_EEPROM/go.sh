#!/bin/bash
cc main.c -o I2CEEPROM-static -lmpsse -Wall -Wextra -lpthread -I../../../include/ -L ../../../build/
