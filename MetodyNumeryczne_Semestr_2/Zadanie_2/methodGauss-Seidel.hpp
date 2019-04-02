#pragma once
#include <vector>



void readDataFromFile(const char *fileName, Matrix *&A, Matrix *&B);

bool converganceCheck(const Matrix *A);
void methodGaussSeidel(Matrix *A, Matrix *B, Matrix *X);