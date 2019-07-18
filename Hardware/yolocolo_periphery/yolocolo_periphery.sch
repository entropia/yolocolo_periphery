EESchema Schematic File Version 4
LIBS:yolocolo_periphery-cache
EELAYER 29 0
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
L Connector:Barrel_Jack J?
U 1 1 5D30005F
P 900 1100
F 0 "J?" H 750 1300 50  0000 C CNN
F 1 "Barrel_Jack" H 900 900 50  0000 C CNN
F 2 "" H 950 1060 50  0001 C CNN
F 3 "~" H 950 1060 50  0001 C CNN
	1    900  1100
	1    0    0    -1  
$EndComp
$Comp
L power:+24V #PWR?
U 1 1 5D300886
P 1650 950
F 0 "#PWR?" H 1650 800 50  0001 C CNN
F 1 "+24V" H 1665 1123 50  0000 C CNN
F 2 "" H 1650 950 50  0001 C CNN
F 3 "" H 1650 950 50  0001 C CNN
	1    1650 950 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D300EC1
P 1650 1250
F 0 "#PWR?" H 1650 1000 50  0001 C CNN
F 1 "GND" H 1655 1077 50  0000 C CNN
F 2 "" H 1650 1250 50  0001 C CNN
F 3 "" H 1650 1250 50  0001 C CNN
	1    1650 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1200 1350 1200
Wire Wire Line
	1650 1200 1650 1250
Wire Wire Line
	1650 950  1650 1000
Wire Wire Line
	1650 1000 1350 1000
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5D301554
P 1350 950
F 0 "#FLG?" H 1350 1025 50  0001 C CNN
F 1 "PWR_FLAG" H 1350 1123 50  0000 C CNN
F 2 "" H 1350 950 50  0001 C CNN
F 3 "~" H 1350 950 50  0001 C CNN
	1    1350 950 
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5D3017DC
P 1350 1250
F 0 "#FLG?" H 1350 1325 50  0001 C CNN
F 1 "PWR_FLAG" H 1350 1423 50  0000 C CNN
F 2 "" H 1350 1250 50  0001 C CNN
F 3 "~" H 1350 1250 50  0001 C CNN
	1    1350 1250
	-1   0    0    1   
$EndComp
Wire Wire Line
	1350 1200 1350 1250
Connection ~ 1350 1200
Wire Wire Line
	1350 1200 1650 1200
Wire Wire Line
	1350 950  1350 1000
Connection ~ 1350 1000
Wire Wire Line
	1350 1000 1200 1000
$Comp
L Switching_Regulators:R-78E3.3-0.5 U?
U 1 1 5D305EE7
P 3250 1000
F 0 "U?" H 3075 750 50  0000 C CNN
F 1 "R-78E3.3-0.5" H 3250 1125 50  0000 C CNN
F 2 "" H 3250 1000 50  0001 C CNN
F 3 "https://cdn-reichelt.de/documents/datenblatt/D400/R-78EXX-0.5.pdf" H 3250 1000 50  0001 C CNN
	1    3250 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5D3082C3
P 2200 1200
F 0 "C?" H 2318 1246 50  0000 L CNN
F 1 "100μF" H 2318 1155 50  0000 L CNN
F 2 "" H 2238 1050 50  0001 C CNN
F 3 "~" H 2200 1200 50  0001 C CNN
	1    2200 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D309A9E
P 2650 1200
F 0 "C?" H 2765 1246 50  0000 L CNN
F 1 "100nF" H 2765 1155 50  0000 L CNN
F 2 "" H 2688 1050 50  0001 C CNN
F 3 "~" H 2650 1200 50  0001 C CNN
	1    2650 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5D30AA06
P 3850 1200
F 0 "C?" H 3968 1246 50  0000 L CNN
F 1 "100μF" H 3968 1155 50  0000 L CNN
F 2 "" H 3888 1050 50  0001 C CNN
F 3 "~" H 3850 1200 50  0001 C CNN
	1    3850 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5D30AA10
P 4300 1200
F 0 "C?" H 4415 1246 50  0000 L CNN
F 1 "100nF" H 4415 1155 50  0000 L CNN
F 2 "" H 4338 1050 50  0001 C CNN
F 3 "~" H 4300 1200 50  0001 C CNN
	1    4300 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1050 2650 1000
Wire Wire Line
	2650 1000 2950 1000
Wire Wire Line
	2200 1050 2200 1000
Wire Wire Line
	2200 1000 2650 1000
Connection ~ 2650 1000
Wire Wire Line
	3550 1000 3850 1000
Wire Wire Line
	3850 1000 3850 1050
Wire Wire Line
	3850 1000 4300 1000
Wire Wire Line
	4300 1000 4300 1050
Connection ~ 3850 1000
$Comp
L power:+24V #PWR?
U 1 1 5D312186
P 2050 950
F 0 "#PWR?" H 2050 800 50  0001 C CNN
F 1 "+24V" H 2065 1123 50  0000 C CNN
F 2 "" H 2050 950 50  0001 C CNN
F 3 "" H 2050 950 50  0001 C CNN
	1    2050 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 950  2050 1000
Wire Wire Line
	2050 1000 2200 1000
Connection ~ 2200 1000
$Comp
L power:+3.3V #PWR?
U 1 1 5D313437
P 4450 950
F 0 "#PWR?" H 4450 800 50  0001 C CNN
F 1 "+3.3V" H 4465 1123 50  0000 C CNN
F 2 "" H 4450 950 50  0001 C CNN
F 3 "" H 4450 950 50  0001 C CNN
	1    4450 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 950  4450 1000
Wire Wire Line
	4450 1000 4300 1000
Connection ~ 4300 1000
$Comp
L power:GND #PWR?
U 1 1 5D313B44
P 3250 1500
F 0 "#PWR?" H 3250 1250 50  0001 C CNN
F 1 "GND" H 3255 1327 50  0000 C CNN
F 2 "" H 3250 1500 50  0001 C CNN
F 3 "" H 3250 1500 50  0001 C CNN
	1    3250 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 1350 2200 1400
Wire Wire Line
	2200 1400 2650 1400
Wire Wire Line
	4300 1400 4300 1350
Wire Wire Line
	3850 1350 3850 1400
Connection ~ 3850 1400
Wire Wire Line
	3850 1400 4300 1400
Wire Wire Line
	2650 1350 2650 1400
Connection ~ 2650 1400
Wire Wire Line
	2650 1400 3250 1400
Wire Wire Line
	3250 1300 3250 1400
Connection ~ 3250 1400
Wire Wire Line
	3250 1400 3850 1400
Wire Wire Line
	3250 1400 3250 1500
$Comp
L MCU_Module:WeMos_D1_mini U?
U 1 1 5D318183
P 5750 1850
F 0 "U?" H 5500 1100 50  0000 C CNN
F 1 "WeMos_D1_mini" H 6150 2600 50  0000 C CNN
F 2 "Module:WEMOS_D1_mini_light" H 5750 700 50  0001 C CNN
F 3 "https://wiki.wemos.cc/products:d1:d1_mini#documentation" H 3900 700 50  0001 C CNN
	1    5750 1850
	1    0    0    -1  
$EndComp
NoConn ~ 5650 1050
NoConn ~ 5350 1450
$Comp
L power:+3.3V #PWR?
U 1 1 5D31ABB3
P 5850 1000
F 0 "#PWR?" H 5850 850 50  0001 C CNN
F 1 "+3.3V" H 5865 1173 50  0000 C CNN
F 2 "" H 5850 1000 50  0001 C CNN
F 3 "" H 5850 1000 50  0001 C CNN
	1    5850 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 1000 5850 1050
$Comp
L power:GND #PWR?
U 1 1 5D31B6D3
P 5750 2700
F 0 "#PWR?" H 5750 2450 50  0001 C CNN
F 1 "GND" H 5755 2527 50  0000 C CNN
F 2 "" H 5750 2700 50  0001 C CNN
F 3 "" H 5750 2700 50  0001 C CNN
	1    5750 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 2700 5750 2650
NoConn ~ 6150 1350
$Comp
L 74xx:74HC595 U?
U 1 1 5D31E54A
P 8050 1850
F 0 "U?" H 7800 1200 50  0000 C CNN
F 1 "74HC595" H 8250 2400 50  0000 C CNN
F 2 "" H 8050 1850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 8050 1850 50  0001 C CNN
	1    8050 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5D31F4E4
P 8050 1000
F 0 "#PWR?" H 8050 850 50  0001 C CNN
F 1 "+3.3V" H 8065 1173 50  0000 C CNN
F 2 "" H 8050 1000 50  0001 C CNN
F 3 "" H 8050 1000 50  0001 C CNN
	1    8050 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 1000 8050 1250
$Comp
L power:GND #PWR?
U 1 1 5D320AE6
P 8050 2600
F 0 "#PWR?" H 8050 2350 50  0001 C CNN
F 1 "GND" H 8055 2427 50  0000 C CNN
F 2 "" H 8050 2600 50  0001 C CNN
F 3 "" H 8050 2600 50  0001 C CNN
	1    8050 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2600 8050 2550
$Comp
L Device:R R?
U 1 1 5D323BC4
P 7400 2300
F 0 "R?" H 7470 2346 50  0000 L CNN
F 1 "10k" H 7470 2255 50  0000 L CNN
F 2 "" V 7330 2300 50  0001 C CNN
F 3 "~" H 7400 2300 50  0001 C CNN
	1    7400 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2150 7400 2050
Wire Wire Line
	7400 2050 7650 2050
$Comp
L power:GND #PWR?
U 1 1 5D32587A
P 7400 2600
F 0 "#PWR?" H 7400 2350 50  0001 C CNN
F 1 "GND" H 7405 2427 50  0000 C CNN
F 2 "" H 7400 2600 50  0001 C CNN
F 3 "" H 7400 2600 50  0001 C CNN
	1    7400 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2600 7400 2450
$Comp
L Device:R R?
U 1 1 5D327010
P 7400 1200
F 0 "R?" H 7470 1246 50  0000 L CNN
F 1 "10k" H 7470 1155 50  0000 L CNN
F 2 "" V 7330 1200 50  0001 C CNN
F 3 "~" H 7400 1200 50  0001 C CNN
	1    7400 1200
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5D329F9F
P 7400 1000
F 0 "#PWR?" H 7400 850 50  0001 C CNN
F 1 "+3.3V" H 7415 1173 50  0000 C CNN
F 2 "" H 7400 1000 50  0001 C CNN
F 3 "" H 7400 1000 50  0001 C CNN
	1    7400 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 1050 7400 1000
Wire Wire Line
	7650 1750 7400 1750
Wire Wire Line
	7400 1750 7400 1350
Wire Wire Line
	6150 1450 7650 1450
Wire Wire Line
	6150 1550 7300 1550
Wire Wire Line
	7300 1550 7300 1650
Wire Wire Line
	7300 1650 7650 1650
Wire Wire Line
	6150 1650 7200 1650
Wire Wire Line
	7200 1650 7200 1950
Wire Wire Line
	7200 1950 7650 1950
$EndSCHEMATC
