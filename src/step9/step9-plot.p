set xlabel "X position"
set ylabel "Y position"
set zlabel "Velocity"
set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb"white" behind
set terminal svg size 1080,1080 fname 'Verdana' fsize 10
set output 'laplace2d.svg'
set view 30,315
set palette rgbformulae 33,13,10
splot "output.dat" matrix with pm3d
