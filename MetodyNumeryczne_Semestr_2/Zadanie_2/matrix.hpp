#pragma once
#include <fstream>

struct Matrix {
	int rows;
	int columns;
	double**elements;
};

Matrix *newMatrix(int rows, int columns);
void delMatrix(Matrix *a);
Matrix *readMatrix(std::istream stream);
void printMatrix(Matrix const *a, std::ostream stream);

