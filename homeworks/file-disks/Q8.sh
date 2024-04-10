#!/bin/bash
DATA=data.txt
PLOT=gnuplot_data.txt
rm -rf $DATA
for i in {1..1000} 
do 
    echo -n "w: $i " >> $DATA
    python3 disk.py -c -p SATF -A 1000,-1,0 -w $i -s 150 | tail -n 2 | head -n 1 | sed 's/TOTALS    \s*//' >> $DATA
done

awk '{gsub("Total:", "", $NF); print $2, $NF}' data.txt > $PLOT

gnuplot <<-EOFMarker
    set terminal png
    set output 'Q8.png'
    set title "Total Time vs Window Size"
    set xlabel "window size"
    set ylabel "Total Time"
    plot "$PLOT" using 1:2 with linespoints title 'Total'
EOFMarker

rm -rf $DATA $PLOT