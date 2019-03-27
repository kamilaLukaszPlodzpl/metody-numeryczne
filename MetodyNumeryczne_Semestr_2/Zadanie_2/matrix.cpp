#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Matrix *newMatrix(int rows, int columns) {
	Matrix *a = new Matrix;
	a->rows = rows;
	a->columns = columns;
	a->elements = new double *[rows];
	for (int i = 0; i < rows; i++) {
		a->elements[i] = new double[columns];
	}
	return a;
}

void delMatrix(Matrix *a) {
	if (a == nullptr)
		return;
	for (int i = 0; i < a->rows; i++) {
		delete[] a->elements[i];
	}
	delete[] a->elements;
	a = nullptr;
}

Matrix *readMatrix(istream stream) {
	int row;
	int column;
	stream >> row >> column;
	Matrix*a = newMatrix(row, column);
	for (int i = 0; i < a->rows; i++) {
		for (int j = 0; j < a->columns; j++) {
			cin >> a->elements[i][j];
		}
	}
	return a;
}

void printMatrix(Matrix const *a, ostream stream) {
	if (a == nullptr) {
		stream << "[ Null matrix ] \n";
		return;
	}
	for (int i = 0; i < a->rows; i++) {
		stream << '[';
		for (int j = 0; j < a->columns; j++) {
			stream << fixed << setw(7) << setprecision(3) << a->elements[i][j];
		}
		stream << setw(2) << ']' << '\n';
	}
}
