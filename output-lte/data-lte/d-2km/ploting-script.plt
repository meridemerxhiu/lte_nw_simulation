set terminal png
set output "DelayvsPacketSize.png"
set title "Delay vs Packet size in dist=2km "

set xlabel "Delay (seconds)"
set key right top

set ylabel "Packet Size (bytes)"
set grid

plot "10mps" using 1:2 with linespoints title "speed=10m/s", \
     "20mps" using 1:2 with linespoints title "speed=20m/s", \
     "30mps" using 1:2 with linespoints title "speed=30m/s", \
     "50mps" using 1:2 with linespoints title "speed=50m/s", \
     "80mps" using 1:2 with linespoints title "speed=80m/s",

