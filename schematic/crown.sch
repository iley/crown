EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U?
U 1 1 5E09C23A
P 5100 3430
F 0 "U?" H 4456 3476 50  0000 R CNN
F 1 "ATmega328P-PU" H 4456 3385 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 5100 3430 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 5100 3430 50  0001 C CNN
	1    5100 3430
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5E09E149
P 5200 1930
F 0 "#PWR?" H 5200 1780 50  0001 C CNN
F 1 "VCC" H 5217 2103 50  0000 C CNN
F 2 "" H 5200 1930 50  0001 C CNN
F 3 "" H 5200 1930 50  0001 C CNN
	1    5200 1930
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1930 5100 1930
Connection ~ 5200 1930
$Comp
L power:GND #PWR?
U 1 1 5E09EE3B
P 5100 4930
F 0 "#PWR?" H 5100 4680 50  0001 C CNN
F 1 "GND" H 5105 4757 50  0000 C CNN
F 2 "" H 5100 4930 50  0001 C CNN
F 3 "" H 5100 4930 50  0001 C CNN
	1    5100 4930
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5E09F907
P 5900 2230
F 0 "SW?" H 5900 2515 50  0000 C CNN
F 1 "SW_Push" H 5900 2424 50  0000 C CNN
F 2 "" H 5900 2430 50  0001 C CNN
F 3 "~" H 5900 2430 50  0001 C CNN
	1    5900 2230
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E0A0C71
P 6100 2230
F 0 "#PWR?" H 6100 1980 50  0001 C CNN
F 1 "GND" H 6105 2057 50  0000 C CNN
F 2 "" H 6100 2230 50  0001 C CNN
F 3 "" H 6100 2230 50  0001 C CNN
	1    6100 2230
	1    0    0    -1  
$EndComp
Text Label 5700 3630 0    50   ~ 0
LED0B
Text Label 5700 3530 0    50   ~ 0
LED0G
Text Label 5700 3430 0    50   ~ 0
LED0R
Text Label 5700 3130 0    50   ~ 0
LED1R
Text Label 5700 3230 0    50   ~ 0
LED1G
Text Label 5700 3330 0    50   ~ 0
LED1B
Text Label 5700 2530 0    50   ~ 0
LED2R
Text Label 5700 2630 0    50   ~ 0
LED2G
Text Label 5700 2730 0    50   ~ 0
LED2B
$Comp
L power:VCC #PWR?
U 1 1 5E0A1B6C
P 4500 2230
F 0 "#PWR?" H 4500 2080 50  0001 C CNN
F 1 "VCC" H 4517 2403 50  0000 C CNN
F 2 "" H 4500 2230 50  0001 C CNN
F 3 "" H 4500 2230 50  0001 C CNN
	1    4500 2230
	1    0    0    -1  
$EndComp
Text Label 5700 4630 0    50   ~ 0
LED3R
Text Label 5700 4530 0    50   ~ 0
LED3G
Text Label 5700 4430 0    50   ~ 0
LED3B
Text Label 5700 2830 0    50   ~ 0
LED4R
Text Label 5700 4330 0    50   ~ 0
LED4G
Text Label 5700 4230 0    50   ~ 0
LED4B
Text Label 5700 4130 0    50   ~ 0
LED5R
Text Label 5700 4030 0    50   ~ 0
LED5G
Text Label 5700 3930 0    50   ~ 0
LED5B
$EndSCHEMATC
