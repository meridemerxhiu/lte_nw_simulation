set terminal png
set output "delivery-velocity.png"
set title "Delivery Ratio vs Velocity in dist 1km"
set xlabel "Velocity m/s"
set ylabel "Delivery Ratio"
set grid
set key right bottom

plot "-"  title "delivery ratio" with linespoints

5	0.9809
15	0.9837
60	0.986
120	0.9865


