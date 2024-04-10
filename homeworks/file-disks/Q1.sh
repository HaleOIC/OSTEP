#!/bin/bash

requests=("0" "6" "30" "7,30,8" "10,11,12,13")

for request in "${requests[@]}"; do
    echo -n "-a $request: "
    python3 disk.py -c -a $request | tail -n 2 | head -n 1 | sed 's/TOTALS    \s*//'
done

