unset label
clear
set terminal jpg
set output  "ej.jpg"

set title "Gráfica P-V"
set xlabel "V (in^3)"
set ylabel "P (lb/in^2)"

set xrange [-3:3]
set yrange [-1:5]
plot x**2 = 4

