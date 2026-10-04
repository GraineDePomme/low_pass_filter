#!/bin/bash

gcc main.c -o low_pass_filter -lm

for i in {1..100}; do
    rc=$(echo "scale=3; $i/100" | bc)
    echo "rc = $rc"
    ./low_pass_filter 0 5 500 "$rc" > data/"$(printf "data_%03d.csv" "$i")"
done

python3 dataviz.py