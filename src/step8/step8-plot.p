#set dgrid3d 101,101,1
set xlabel "X position"
set ylabel "Y position"
set zlabel "Velocity"
#set style data lines
set terminal svg size 1080,1080 fname 'Verdana' fsize 10
set output 'diffusion2d.svg'
splot "output.dat" matrix with pm3d
