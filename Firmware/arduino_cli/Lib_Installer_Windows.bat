@echo off

set "arduino_cli_path=C:\arduino_cli\arduino-cli.exe"  

call "%arduino_cli_path%" core install esp32:esp32@2.0.17
call "%arduino_cli_path%" lib install NewPing@1.9.7
call "%arduino_cli_path%" lib install FastLED@3.7.0
call "%arduino_cli_path%" lib install ESP32Servo@1.2.1
call "%arduino_cli_path%" lib install "Adafruit BusIO@1.16.1"
call "%arduino_cli_path%" lib install "Adafruit TCS34725@1.4.4"
call "%arduino_cli_path%" lib install "Adafruit GFX Library@1.11.11"
call "%arduino_cli_path%" lib install "Adafruit SSD1306@2.5.13"

exit
