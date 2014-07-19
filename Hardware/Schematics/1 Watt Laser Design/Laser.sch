EESchema Schematic File Version 2  date 3/18/2012 9:16:57 AM
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Laser-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "18 mar 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BC237 Q1
U 1 1 4F65E014
P 4100 5100
F 0 "Q1" H 4300 5000 50  0000 C CNN
F 1 "BC817" H 4350 5250 50  0000 C CNN
F 2 "TO92-EBC" H 4290 5100 30  0001 C CNN
	1    4100 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3950 4200 4250
Wire Wire Line
	4200 2500 4200 2700
Wire Wire Line
	3400 5650 3400 5500
Wire Wire Line
	6550 1800 6850 1800
Wire Wire Line
	5750 1800 5550 1800
Wire Wire Line
	3900 5100 3900 5100
Wire Wire Line
	3000 5100 3400 5100
Connection ~ 3400 5100
Wire Wire Line
	5550 1800 5550 1700
Wire Wire Line
	5550 2200 5550 2350
Wire Wire Line
	6150 2300 6850 2300
Wire Wire Line
	6850 2300 6850 2650
Wire Wire Line
	4200 4750 4200 4900
Wire Wire Line
	4200 5300 4200 5500
Wire Wire Line
	4200 5500 3400 5500
Wire Wire Line
	4200 3100 4200 3350
$Comp
L INDUCTOR L1
U 1 1 4F64A692
P 4200 3650
F 0 "L1" V 4150 3650 40  0000 C CNN
F 1 "INDUCTOR" V 4300 3650 40  0000 C CNN
	1    4200 3650
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 4F64A638
P 4200 2900
F 0 "D1" H 4200 3000 50  0000 C CNN
F 1 "LED" H 4200 2800 50  0000 C CNN
	1    4200 2900
	0    1    1    0   
$EndComp
$Comp
L VCC #PWR?
U 1 1 4F64A615
P 4200 2500
F 0 "#PWR?" H 4200 2600 30  0001 C CNN
F 1 "VCC" H 4200 2600 30  0000 C CNN
	1    4200 2500
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 4F64A592
P 4200 4500
F 0 "R3" V 4280 4500 50  0000 C CNN
F 1 "R" V 4200 4500 50  0000 C CNN
	1    4200 4500
	-1   0    0    1   
$EndComp
Text Label 6850 2500 0    60   ~ 0
I2
Text Notes 6950 1700 0    60   ~ 0
I2 = Vref/R2       where Vref = 1.25 Volts = Vout - Vadj
$Comp
L R R?
U 1 1 4F64A272
P 6850 2050
F 0 "R?" V 6930 2050 50  0000 C CNN
F 1 "R2" V 6850 2050 50  0000 C CNN
	1    6850 2050
	-1   0    0    1   
$EndComp
$Comp
L C C2
U 1 1 4F64A1F8
P 5550 2000
F 0 "C2" H 5600 2100 50  0000 L CNN
F 1 "C" H 5600 1900 50  0000 L CNN
	1    5550 2000
	1    0    0    -1  
$EndComp
$Comp
L GND GND?
U 1 1 4F64A1F7
P 5550 2350
F 0 "GND?" H 5550 2300 30  0000 C TNN
F 1 "GND" H 5550 2280 30  0001 C CNN
	1    5550 2350
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 4F64A1D5
P 5550 1700
F 0 "#PWR?" H 5550 1800 30  0001 C CNN
F 1 "VCC" H 5550 1800 30  0000 C CNN
	1    5550 1700
	1    0    0    -1  
$EndComp
$Comp
L LM317 U?
U 1 1 4F64A1B8
P 6150 1950
F 0 "U?" H 6150 2250 60  0000 C CNN
F 1 "LM317" H 6200 1700 60  0000 L CNN
	1    6150 1950
	1    0    0    -1  
$EndComp
$Comp
L GND GND
U 1 1 4F64A014
P 3400 5650
F 0 "GND" H 3400 5600 30  0000 C TNN
F 1 "GND" H 3400 5580 30  0001 C CNN
	1    3400 5650
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 4F649781
P 3650 5100
F 0 "R1" V 3730 5100 50  0000 C CNN
F 1 "R" V 3650 5100 50  0000 C CNN
	1    3650 5100
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 4F64974D
P 3400 5300
F 0 "C1" H 3450 5400 50  0000 L CNN
F 1 "C" H 3450 5200 50  0000 L CNN
	1    3400 5300
	1    0    0    -1  
$EndComp
Text Notes 950  1400 0    60   ~ 0
Q1: BC817 has a CE current limit of 500 mA.\nR1: Use to limit voltage swing.\nC1: Use to smooth PWM from PIC.\n\nNot sure if still need a LM 317 and resistor to provide constant current to collecter pin of Q1.\nNot sure if L1 is needed. Could help stabilize current flow.
Text Notes 1600 4150 0    60   ~ 0
Some PIC
$Comp
L PIC16F627 U?
U 1 1 4F649481
P 1700 5050
F 0 "U?" H 2000 5850 60  0000 C CNN
F 1 "PIC16F627" H 2150 4250 60  0000 C CNN
	1    1700 5050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
