# BzBox-MachineLearning-Local
Machine Learning algorithms in C++ for posterior Particle implementation.

Build
=====
Run build.sh from Particle folder.

Usage
=====
After building, running ./test in the bin folder will load the file defined in main.cpp and extract features from it with the filters defined in create_filters.cpp.

The classifier will decide a beehive state per 2 seconds of data (to keep the test small) and display it via standard output.

The features will be saved in a file named energy_bands.dat, as a time series of the energy in each frequency band.

License
=======

**This software is released under the [MIT License](http://opensource.org/licenses/MIT).**

The MIT License (MIT)

Copyright (c) 2016 SparkFun Electronics, Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.