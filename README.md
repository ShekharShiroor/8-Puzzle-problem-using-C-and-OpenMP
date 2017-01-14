# Project

The C++ source code uses the Brute force approach to find the solution to the 8-Puzzle problem. I have used OpenMP such that on every change in the puzzle new thread is spawned and the change happens in parallel. The code tries every scenario of the 8-puzzle until the solution is found. 

The code not working properly due to the limit on the number of threads that the OpenMP can make.

The 8-puzzle.cpp contains the code for the 8-puzzle problem


# Future Scope:- 
The code can be pushed on the GPU (Cuda) using NVCC for getting the result.

