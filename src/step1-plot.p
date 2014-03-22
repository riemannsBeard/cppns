set xlabel "X position"
set ylabel "Velocity"
set terminal svg size 1080,1080 fname 'Verdana' fsize 10
set output 'lin1d.svg'
plot "data-before.dat" using 1:2 title "Linear Diffusion in 1D", "data-after.dat" using 1:2
