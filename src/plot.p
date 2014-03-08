set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "MyPlot"
set xlabel "Things (meters)"
set ylabel "Forces (kN)"
#set key 0.01,100
#set label "Yield Point" at 0.003,260
#set arrow from 0.0028,250 to 0.003,280
set xr [0.0:8]
set yr [0:10]
set terminal svg size 350,262 fname 'Verdana' fsize 10
set output 'output.svg'
plot 'output.dat'