#include <iostream>
#include <string>
#include "matrix.hpp"
#include "methodGauss-Seidel.hpp"
using namespace std;


int main(int argc, char* argv[])
{
	cout << "Podaj nazwe pliku\n";
	string fileName;
	cin >> fileName;

	cout << "########################################\n";

	char condition = 'v';
	do
	{
		cout << "Wybierz warunek stopu:\n"
			<< "\t i. iteracje\n"
			<< "\t d. dokladnosc\n";
		cin >> condition;
	} while (condition != 'i' && condition !='d');

	//Wczytanie macierzy A B
	Matrix *A, *B;
	readDataFromFile(fileName.c_str(), A, B);

	//Generowanie macierzy X
	Matrix *X = newMatrix(B->rows, 1);
	for (int i = 0; i < B->rows; i++)
	{
		X->elements[i][0] = 0;
	}
	cout << "macierz A: \n";
	printMatrix(A);
	cout << "macierz B: \n";
	printMatrix(B);
	cout << "----------------------------------------\n";
	if (!converganceCheck(A))
	{
		cout << "macierz A nie jest zbie¿na\n";
	}
	else
	{
		if (condition == 'i')
		{
			int iteration = 10;
			cout << "Podaj ilosc iteracji\n";
			cin >> iteration;
			for (int i = 0; i < iteration; i++)
				methodGaussSeidel(A, B, X);
		}
		else
		{
			throw new exception("Not implemented");
			return 1;
		}
		cout << "obliczona macierz X:\n";
		printMatrix(X);
	}

	cin.get();
	cin.get();
	return 0;
}