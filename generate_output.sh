for i in */; do
 echo "do make in $i"
 ( cd $i && make )
done

./C-JuliaSets/julia -2 2 -2 2 1000 1000 -1.037 0.17 > juliaset.csv
./Cpp-Mandelbrot/mandelbrot -2 2 -2 2 1000 1000 > mandelbrot.csv