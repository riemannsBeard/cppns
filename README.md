navier-stokes-steps
===================

Reimplementation of the 12 steps to Navier Stokes in C++, with Eigen and GnuPlot

The original was written by Lorena Barba under the title ["CFD Python: 12 steps to Navier-Stokes"](http://lorenabarba.com/blog/cfd-python-12-steps-to-navier-stokes/) under the 
[Attribution-NonCommercial-ShareAlike 3.0 Unported \(CC BY-NC-SA 3.0\)].

## Dependencies ##
-Eigen3
-GnuPlot (Only needed to view data, will compile and run without)
-Cmake
-Some standard C++ libraries that should be included with your compiler
-Standard GNU/Linux Build chain (build-essentials on debian)

## Compiling ##

Currently only compiles for Linux. Minimal effort should be required to make it work for Windows.

Downloading and compiling this program can be done by doing the following:


	git clone https://github.com/jcc242/cppns.git #Downloads the code from github
	mkdir cppns-build #Creates a build directory. CMake likes out of source builds
	cd cppns-build #Change directory to the build directory
	cmake ../cppns #Tells cmake where the source files are, also generates the makefiles
	make #Compiles
	
## Running ##

After cimpiling run the program created, cppns

	./cppns

You will be prompted for a number corresponding to which step you wish to run. They correspond as follows:

1. Step 1: 1D Linear Convection
2. Step 2: 1D Nonlinear Convection
3. Step 3: 1D Diffusion
4. Step 4: 1D Burger's Equation
5. Array Operations Test
6. Step 5: 2D Linear Convection
7. Step 6: 2D Nonlinear Convection
8. Step 7: 2D Diffusion
9. Step 8: 2D Burgers
10. To come...

The results are output into a folder corresponding to the step name (i.e. the plot and data for step 2 are created in the folder step2/). Included in the src/ folder are corresponding gnuplot scripts of the name "step#-plot.p" where # is the corresponding step. Most of these files are actually identical (all 1Ds the same, all 2Ds the same, etc.). Just copy this plot folder into your data folder and run "gnuplot step8-plot.p" to generate an SVG file with the plot.

Please let me know on github if you have any issues.