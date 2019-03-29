#pragma once
#include <vector>



void readDataFromFile(const char *fileName, Matrix *&A, Matrix *&B);

bool converganceCheck(Matrix *A);
void formulaFromWiki(Matrix *A, Matrix *B, Matrix *X);