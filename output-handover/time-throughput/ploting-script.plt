set terminal png
set output "Time vs Throughput_.png"
set title "time vs throughput"

set xlabel "time (s)"
set key right bottom

set ylabel "Throughput (kbps)"
set grid

plot "data1" using 1:2 with linespoints title "f1", \
     "data2" using 1:2 with linespoints title "f3", \
     "data3" using 1:2 with linespoints title "f5", \
     "data4" using 1:2 with linespoints title "f7", \
     "data5" using 1:2 with linespoints title "f9", \
     "data6" using 1:2 with linespoints title "f11", \
     "data7" using 1:2 with linespoints title "f13", \
     "data8" using 1:2 with linespoints title "f15"

