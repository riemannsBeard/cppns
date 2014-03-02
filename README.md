navier-stokes-steps
===================

Reimplementation of the 12 steps to Navier Stokes in C++, with Eigen and GnuPlot

The original was written by Lorena Barba under the title ["CFD Python: 12 steps to Navier-Stokes"](http://lorenabarba.com/blog/cfd-python-12-steps-to-navier-stokes/) under the 
[Attribution-NonCommercial-ShareAlike 3.0 Unported \(CC BY-NC-SA 3.0\)].

## Dependencies ##
-Eigen3
-GnuPlot
-Cmake
-Build chain (build-essentials on debian)

## Compiling ##

Currently only compiles for linux. Minimal effort should be required to make it work for Windows.

Downloading and compiling this program can be done by doing the following:


	git clone https://github.com/jcc242/cppns.git #Downloads the code from github
	mkdir cppns-build #Creates a build directory. CMake likes out of source builds
	cd cppns-build #Change directory to the build directory
	cmake ../cppns #Tells cmake where the source files are, also generates the makefiles
	make #Compiles

After that run the program created, cppns

	./cppns

You will be prompted for a number corresponding to which step you wish to run. The results are output into a folder corresponding to the step name (i.e. the plot and data for step 2 are created in the folder step2/).

Please let me know on github if you have any issues.

Further instructions on the dependencies are forthcoming.
