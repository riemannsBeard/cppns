# Gnuplot script file for plotting data in file "force.dat"
# This file is called   force.p
set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Test Data"
set xlabel "Time Step?"
set ylabel "Wave Speed"
#set key 0.01,100
#set label "Yield Point" at 0.003,260
#set arrow from 0.0028,250 to 0.003,280
set xr [0.0:2.0]
set yr [0:4]
plot    "data-before.dat" using 1:2 title 'Before' with linespoints , \
            "data-after.dat" using 1:2 title 'After' with points
pause -1
