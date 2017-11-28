#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include <fstream>
#include <string>

int** buildAdjMatrix(const char* filename, int* nVertex);
void printMatrix(int matrixSize, int** matrix);
void printSolution(const int size, const int* solution);

#endif