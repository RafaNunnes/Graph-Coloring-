#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

//int* availableColors;
int* constructSolution(const int matrixSize, int** matrix);
int* constructNewSolution(const int matrixSize, int** matrix, const int* solution);

#endif