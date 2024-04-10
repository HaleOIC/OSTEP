#!/bin/bash

requests=("0" "6" "30" "7,30,8" "10,11,12,13")
seek_rates=("2" "4" "8" "10" "40" "0.1")

for request in "${requests[@]}"; do
  for rate in "${seek_rates[@]}"; do
    echo -n "-S $rate -a $request: "
    python3 disk.py -c -S $rate -a $request | tail -n 2 | head -n 1 | sed 's/TOTALS    \s*//'
  done
done

