Parallel Life is a parallel implementation of Conway's Game of Life algorithm. The project utilizes parallel programming techniques to simulate the game of life on a large grid of cells. The simulation is highly optimized and designed to run on multi-core processors, making it fast and efficient. The project provides an intuitive graphical user interface to visualize the simulation and control various settings. The project also includes a set of test cases to validate the correctness and performance of the algorithm. Parallel Life is written in C++ and uses the OpenMP library for parallelization. The code is highly modular and well-documented, making it easy to extend and modify.


This directory contains the following files:
* compare.cpp: code to compare two output files
* Makefile: to build the code
* io.h: input/output routines 
* life_skeleton.cpp: skeleton file for parallel code of Conway's Game of Life
* life.slurm: script file for batch processing of parallel code of Conway's Game of Life
* result_X_Y: result file for test Y of program X
* setup.sh: script file to set up Intel compiler
* test_X_Y: test case Y for program X
* test_X.sh: test script for program X
* timer.h: timing routines 
