set xlabel "X position"
set ylabel "Velocity"
set terminal svg size 1080,1080 fname 'Verdana' fsize 10
set output 'diffusion.svg'
set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb"#ffffff" behind
plot "output.dat" using 1:2 title "Diffusion in 1D"
