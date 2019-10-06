*Meson build for the Antigrain C++ library*

This repository provides the Antigrain library from the 2.4 version branch with the addition of a Meson build and some fixes.

You can find more information about the Antigrain library in the [Antigrain library's homepage](http://antigrain.com/).

## Why Meson ?

Because it is better than Makefiles and works better with [Little Library Helper](https://github.com/franko/lhelper) to easily build and install the antigrain library on Linux or Windows using MinGW.

## How to use it?

From the source directory:

```sh
meson setup build
ninja -C build
ninja -C build install
```
more information from the [Meson Quick guide](https://mesonbuild.com/Quick-guide.html).

## Getting started with Little Library Helper

The Little Library Helper let you create isolated build environments without messing with system-wide installs.

Here how to use the Antigrain library with the Little Library Helper.

```sh
# Create a build environment named 'agg',
lhelper create agg

 # Start a new shell in the 'agg' build environment.
lhelper start agg

# Install the agg library in the current build environment.
lhelper install libagg

# Compile whatever project that may need the agg library.
# The agg library will be visible with pkg-config and CMake.

exit # end the shell in the 'agg' build environment
```

## What is the Antigrain library? (extract from the original Antigrain library's README)

The Anti-Grain Geometry Project
-------------------------------

A high quality rendering engine for C++
[http://antigrain.com](http://antigrain.com)

Anti-Grain Geometry - Version 2.4
Copyright (C) 2002-2005 Maxim Shemanarev (McSeem)

Permission to copy, use, modify, sell and distribute this software
is granted provided this copyright notice appears in all copies.
This software is provided "as is" without express or implied
warranty, and with no claim as to its suitability for any purpose.
