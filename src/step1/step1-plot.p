set xlabel "X position"
set ylabel "Velocity"
set terminal svg size 1080,1080 fname 'Verdana' fsize 10
set output 'lin1d.svg'
set object 1 rectangle from screen 0,0 to screen 1,1 fillcolor rgb"#ffcccc" behind
plot "data-before.dat" using 1:2 title "Linear Convection in 1D", "data-after.dat" using 1:2
