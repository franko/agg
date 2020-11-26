*Meson build for the Antigrain C++ library*

A high quality rendering engine for C++
[antigrain github mirror](https://franko.github.io/antigrain/).

This repository provides the Antigrain library from the 2.4 version branch with the addition of a Meson build and some fixes.

You can find more information about the Antigrain library in the [antigrain github mirror](https://franko.github.io/antigrain/).

Please note tha the original domain [antigrain.com](http://antigrain.com) may not work and the [antigrain github mirror](https://franko.github.io/antigrain/)
reproduce its contents without modifications.

## Why Meson ?

Meson is an open source build system meant to be both extremely fast, and, even more importantly, as user friendly as possible.

Meson is used in many major open source projects.
It is better than using simple Makefiles and works better with [Little Library Helper](https://github.com/franko/lhelper)
to easily build and install the antigrain library on Linux or Windows using MinGW.

To install Meson have a look at the official [getting Meson](https://mesonbuild.com/Getting-meson.html) webpage.

Using Meson you can build the Antigrain library using all the standard options the Meson offers.

The library is built as a static library and in addition many of the original examples will be compiled.
A pkg-config file is also provided when installing the library.

## How to use it?

From the source directory:

```sh
meson setup build
ninja -C build
ninja -C build install
```
more information from the [Meson Quick guide](https://mesonbuild.com/Quick-guide.html).

# An introduction to the Antigrain library

The author of this page propose an [introduction to the Antigrain library](https://franko.github.io/agg-intro).
While not complete it can be useful for people beginning with the Antigrain library.

Otherwise please refer to the original Antigrain website using the [antigrain github mirror](https://franko.github.io/antigrain/).

# What is the Antigrain library? (extract from the original Antigrain library's README)

## The Anti-Grain Geometry Project

A high quality rendering engine for C++
[http://antigrain.com](http://antigrain.com)

Anti-Grain Geometry - Version 2.4
Copyright (C) 2002-2005 Maxim Shemanarev (McSeem)

Permission to copy, use, modify, sell and distribute this software
is granted provided this copyright notice appears in all copies.
This software is provided "as is" without express or implied
warranty, and with no claim as to its suitability for any purpose.
