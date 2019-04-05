#pragma once
#include "matrix.hpp"
#include "methodGauss-Seidel.hpp"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


void readDataFromFile(const char *fileName, Matrix *&A, Matrix *&B)
{
	fstream stream(fileName);
	if (!stream.good())
	{
		std::cout << "Problem odczytu pliku!\n";
		throw new exception("Problem odczytu pliku!");
	}
	while (!stream.eof())
	{
		std::string x;
		do
		{
			stream >> x;
			std::cin << x << " ";

		} while (x != "|");
	}
}

bool converganceCheck(const Matrix *A ) {
	for (int i = 0; i < A->rows; i++) {
		double sum = 0;
		for (int j = 0; j < A->columns; j++) {
			if (i != j) {
				sum += abs(A->elements[i][j]);
			}
		}
		if (abs(A->elements[i][i]) <= sum) {
			return false;
		}
	}
	return true;
}


void methodGaussSeidel(Matrix *A, Matrix *B, Matrix *X)
{
	int n = A->rows;
	std::vector<double> x(n);
	for (int i = 0; i < n; i++)
	{
		double xi = 1 / (A->elements[i][i]);
		//Nawias
		double bi = B->elements[i][0];
		double firstSum = 0, secondSum = 0;
		
		for (int j = 0; j < i; j++)
		{
			double temp = (A->elements[i][j])*(X->elements[j][0]);
			firstSum += temp;
		}
		for (int j = i+1; j < n; j++)
		{
			double temp = (A->elements[i][j])*(X->elements[j][0]);
			secondSum += temp;
		}
		
		xi *= (bi - firstSum - secondSum);
		//*/
		X->elements[i][0] = xi;
	}
}