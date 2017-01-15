# BzBox-MachineLearning-Local
Machine Learning algorithms in C++ for posterior Particle implementation.

Build
=====
Run build.sh from Particle folder.

Usage
=====
After building, running ./test will load test.dat from resources and extract features from it with the filters defined in coeffs.txt.
The classifier will decide a beehive state per 2 seconds of data (to keep the test small) and display it via standard output.

The results will be saved in a file named energy_bands.dat, as a time series of the energy in each frequency band.

The time window length for computing energy can be changed in params.h (requires rebuilding).
