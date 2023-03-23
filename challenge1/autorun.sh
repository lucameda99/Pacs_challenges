#!/bin/bash
make clean
make
./main_getpot_muparser
python visualize.py
xdg-open output.png
xdg-open convergence_rate.png
