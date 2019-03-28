#include "matrix.hpp"
#include "methodGauss-Seidel.hpp"
#include <iostream>

bool converganceCheck( Matrix *A ) {
	double sum = 0;
	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->columns; i++) {
			if (i = !j) {
				sum = sum + A->elements[i][j];
			}
		}
		if (A->elements[i][i] < sum) {
			return false;
		}
	}
	return true;
}
