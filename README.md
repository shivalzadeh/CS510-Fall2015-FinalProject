# CS510-Fall2015-FinalProject
### Shiva Barzili

complex.c and complex.h :
 - These files were previously written this semester to work with complex 
numbers. The first file, complex.c. It has the code to square, add, multiply, print complex numbers. also,we have complex.h. This contains the declarations of the class.

cplane.c and cplane.h :
- In cplane.c and cplane.h we have the newly created structure type CPLANE         which stores a complex plane, cplane.c, and the corresponding header file cplane.h. Within cplane.c we have the ability to actually create the 
complex plane and print it.

julia.c :
- This is where we work with the complex and cplane code. We will create a    function that takes eight (8) command line arguments and appropriately p        arsees them into CPLANE and COMPLEX structures. Using these inputs, a co        mplex plane will be created using the CPLANE type. Whenever there is a c        omplex point in this creation, the juliamap function will iterate until it has reached a magnitude larger than two. The number of iterations will then be printed to the screen as well as a CSV line regarding the calculated values.

cplane.cpp and cplane.hpp :
Very similar to cplane.c and cplane.h above, we have cplane.cpp and cpla    ne.hpp which are a C++ library with a cplane class. This class differs,         however, in that it does not store COMPLEX types but rather std::complex         <long double> types. The other glaring difference is that instead of mu        ltidimensional C arrays it utilizes boost::numeric::ublas::matrix
<std::complex<long double> > type. All that along with the obvious change form    C to C++ for both cplane.cpp and the corresponding cplane.hpp header file.

julia.cpp and julia.hpp

 - Here we have the simple implementation of the previously defined juliamap function using std::complex<long double> instead of COMPLEX type like         that of the C portion.
 
 mandelbrot.cpp :
 - This is the main functionality of the mandelbrot part of the project.     Here we take six (6) command line arguments properly parsed to be used         in the cplane constructor. We will again iterate over a complex plane 
 created from the given arguments and and iterate the function juliamap. 
 Again we will finish by outputting a single CSV line.
 
 generate_csv.sh :
 - Here we have a bash script that executes make properly to build and exec    ute our julia and madelbrot programs using the given lines of:
       C-JuliaSet/julia -2 2 -2 2 1000 1000 -1.037 0.17 > juliaset.csv
       Cpp-Mandelbrot/mandelbrot -2 2 -2 2 1000 1000 > mandelbrot.csv
This will generate the default CSV datafiles.

plot_data.py :
 - Finally, there is the python script. Here we take in and parse a single     command line argument of the name of a CSV file. We then proceed to load         the given file into a pandas dataframe. Continuing, we use the tools 
 from matplotlib to create a 2D heatmapped plot and save it as a JPEG file.
 
 
