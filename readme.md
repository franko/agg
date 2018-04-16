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

Modifications from the original repository
------------------------------------------

This repository includes some (minor) modifications of the 2.4 branch.

Meson and Ninja are used to build the library and the examples. To compile use the following command:

```
meson --buildtype=release build-release
cd build-release
ninja
```

Currently only Linux and Windows are supported using the meson build.
