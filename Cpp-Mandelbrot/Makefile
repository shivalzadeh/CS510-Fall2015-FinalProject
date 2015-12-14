
# Makefile used to compile and run program as part of the mandelbrot directory

CC=g++
CFLAGS=-c -Wall

all:mandelbrot 

run: all
	./mandelbrot -2 2 -2 2 100 100

mandelbrot: cplane.o julia.o  mandelbrot.o
	$(CC) cplane.o julia.o mandelbrot.o -o mandelbrot

cplane.o: cplane.cpp
	$(CC) $(CFLAGS) cplane.cpp

julia.o: julia.cpp
	$(CC) $(CFLAGS) julia.cpp

mandelbrot.o: mandelbrot.cpp
	$(CC) $(CFLAGS) mandelbrot.cpp

clean:
	rm *o mandelbrot