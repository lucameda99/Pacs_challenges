#!/bin/bash
make clean
make
./CN_solver
python visualize.py
xdg-open output.png
