#!/bin/bash # Standard line to start a bash script. '!/bin/bash' is the local bash address.

# Defines some useful variables
min=-.785
max=.785
points=1000
creal=-0.70176
cimag=-0.3842

# Runs julia.c, saving the output in juliaset.csv.
(echo $min; echo $max; echo $min; echo $max; echo $points; echo $points; echo $creal; echo $cimag) | C-JuliaSets/julia | sed '1,8d' > juliasetzoom5.csv
# Runs mandelbrot.cpp, saving the output in mandelbrot.csv.
(echo $min; echo $max; echo $min; echo $max; echo $points; echo $points) | Cpp-Mandelbrot/mandelbrot | sed '1,6d'  > mandelbrotzoom.csv
