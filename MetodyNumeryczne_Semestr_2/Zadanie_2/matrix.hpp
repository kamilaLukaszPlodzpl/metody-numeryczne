#pragma once

struct Matrix {
	int rows;
	int columns;
	double**elements;
};

Matrix *newMatrix(int rows, int columns);
void delMatrix(Matrix *a);
Matrix *readMatrix(istream stream);
void printMatrix(Matrix const *a, ostream stream);

