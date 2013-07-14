Raspberry-Pi-Utils
==================

Raspi related librairies &amp; tools

You can found a copy of this software here: https://github.com/ronanguilloux/Raspberry-Pi-Utils

Raspberry Pi PCD8544 Library
----------------------------

A simple PCD8544 LCD (Nokia3310/5110) driver. Target board is Raspberry Pi. This driver uses 5 GPIOs on target board with a bit-bang SPI implementation (hence, may not be as fast but seems fast enough). The pcd8544_cli tool, to be compiled, allow you to display messages freely on the display. Makes use of WiringPI-library of _Gordon Henderson_ (https://projects.drogon.net/raspberry-pi/wiringpi/)

![Circuit](https://raw.github.com/ronanguilloux/Raspberry-Pi-Utils/master/PCD8544/resources/images/circuit.png)

![Schema](https://raw.github.com/ronanguilloux/Raspberry-Pi-Utils/master/PCD8544/resources/images/setup.jpg)

Image source & inspiration: http://binerry.de/post/25787954149/pcd8544-library-for-raspberry-pi


Requirements
------------

This makes use of [WiringPI-library of Gordon Henderson](https://projects.drogon.net/raspberry-pi/wiringpi) - so the WiringPI-library is required to be [installed](https://projects.drogon.net/raspberry-pi/wiringpi/download-and-install/). 


Usage
-----

The PCD8544 file is a library, the pcd8544_cli is a cli-tool example, to be extended by you.
Since gcc is installed on Raspberry Pi images, you can easily build them:

``` bash
$ cc -o pcd8544_cli pcd8544_cli.c PCD8544.c  -L/usr/local/lib -lwiringPi
```

Usage:

``` bash
pcd8544_cli [options] <text to display>
```

Available options:
* -h: show this help on usage & options
* -i: show IP address
* -d: show datetime

Print help informations in the terminal (will reset the display)

``` bash
$ sudo ./pcd8544_cli -h
```

Example 1: Print "Foooooooooooooooooooooooooo" on the display:

``` bash
$ sudo ./pcd8544_cli "Foooooooooooooooooooooooooo"
```

Example 2: Print current IP address on the display:

``` bash
$ sudo ./pcd8544_cli -i
```

Example 3: Print current datetime on the display:

``` bash
$ sudo ./pcd8544_cli -d
```


Copyrights
----------

PCD8544.c & PCD8544.h are copyright (C) 2010 Limor Fried, Adafruit Industries

CORTEX-M3 version by Le Dang Dung, 2011 LeeDangDung@gmail.com (tested on LPC1769)

Raspberry Pi version:

* initiated by Andre Wussow, 2012, desk@binerry.de, https://github.com/binerry/RaspberryPi
* hacked by Ronan Guilloux, 2013, https://github.com/ronanguilloux/Raspberry-Pi-Utils


License
-------

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

