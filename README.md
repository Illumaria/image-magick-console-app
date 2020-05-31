# image-magick-test

## Overview
This simple C++ command-line application is designed to demonstrate some basic functionality of Magick++ API from [ImageMagick](https://imagemagick.org/) library.

## Prerequisites

* cmake: 3.16 or higher
* ImageMagick: 6.9.0 or higher

## Build

To build the current release on Linux systems, open the terminal and run the following commands:

```
$ git clone https://github.com/Illumaria/image-magick-test.git
$ cd image-magick-test/
$ cmake .
$ make
```

#### To try the application, run:

```
$ ./image-magick-test
```
The image 'img.jpg' can be used for testing purposes. Feel free to use your own images.

## Usage

  -  ```load <name> <filename>``` or ```ld <name> <filename>``` loads a JPG-file with with the name \<filename\> and saves it in memory by the name \<name\>.
  -  ```store <name> <filename>``` or ```s <name> <filename>``` saves the image with the name \<name\> to a JPG-file with the name \<filename\>.
  -  ```blur <from_name> <to_name> <radius>``` blurs the image \<from_name\> by specifying the \<radius\> value and saves it in memory by the name \<to_name\>. Please note that due to sigma value being hardcoded to value '2.0', \<radius\> value of either '0' or at a minimum double that of the sigma is recommended.
  -  ```resize <from_name> <to_name> <new_width> <new_height>``` changes the dimensions of the image \<from_name\> to width \<new_width\> and height \<new_height\> and saves it in memory by the name \<to_name\>. Please note that aspect ratio is ignored.
  -  ```help``` or ```h``` prints this help message.
  -  ```exit```, ```quit``` or ```q``` quits the application.
