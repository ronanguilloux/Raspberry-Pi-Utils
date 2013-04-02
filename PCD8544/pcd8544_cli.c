/*
=================================================================================
 Name        : pcd8544_cli.c
 Version     : 0.1

 Inspirated by http://github.com/binerry/RaspberryPi/tree/master/libraries/c/PCD8544

 Copyright (C) 2013 by Ronan Guilloux, @arno_u_loginlux, http://github.com/ronanguilloux

 Description :
     A simple PCD8544 LCD (Nokia3310/5110) for Raspberry Pi for displaying some string.

     Makes use of

     * WiringPI-library of Gordon Henderson (https://projects.drogon.net/raspberry-pi/wiringpi/)
	 * Raspberry Pi PCD8544 Library
	 * http://binerry.de/post/25787954149/pcd8544-library-for-raspberry-pi.

	 Recommended connection (http://www.raspberrypi.org/archives/384):
	 LCD pins      Raspberry Pi
	 LCD1 - GND    P06  - GND
	 LCD2 - VCC    P01 - 3.3V
	 LCD3 - CLK    P11 - GPIO0
	 LCD4 - Din    P12 - GPIO1
	 LCD5 - D/C    P13 - GPIO2
	 LCD6 - CS     P15 - GPIO3
	 LCD7 - RST    P16 - GPIO4
	 LCD8 - LED    P01 - 3.3V

================================================================================
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.
================================================================================
 */
#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include "PCD8544.h"

// pin setup
int _din = 1;
int _sclk = 0;
int _dc = 2;
int _rst = 4;
int _cs = 3;

// lcd contrast
int contrast = 50;

//int main (void)
int main(int argc, char *argv[])
{

  if (argc > 3)
  {
    printf("Only one or two argument expected\n");
    exit(1);
  }


  // check wiringPi setup
  if (wiringPiSetup() == -1)
  {
	printf("wiringPi-Error\n");
    exit(1);
  }

  // init and clear lcd
  LCDInit(_sclk, _din, _dc, _cs, _rst, contrast);
  LCDclear();

  // get system usage / info
  struct sysinfo sys_info;
  if(sysinfo(&sys_info) != 0)
  {
      printf("sysinfo-Error\n");
  }

  // build screen
  LCDdrawstring(0, 0, argv[1]);
  LCDdisplay();

  return 0;
}
