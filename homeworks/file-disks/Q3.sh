#!/bin/bash

requests=("0" "6" "30" "7,30,8" "10,11,12,13")
rotation_rates=("0.1" "0.5" "0.01")

for request in "${requests[@]}"; do
  for rate in "${rotation_rates[@]}"; do
    echo -n "-R $rate -a $request: "
    python3 disk.py -c -R $rate -a $request | tail -n 2 | head -n 1 | sed 's/TOTALS    \s*//'
  done
done

