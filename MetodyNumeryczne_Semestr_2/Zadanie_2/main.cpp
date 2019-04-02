#include <iostream>
#include <string>
#include "matrix.hpp"
#include "methodGauss-Seidel.hpp"
#define AUTO
using namespace std;


int main(int argc, char* argv[])
{
	cout << "Podaj nazwe pliku\n";
	string fileName = ".\\matrix\\d.txt";
	cin >> fileName;

	cout << "########################################\n";

	char condition = 'd';
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
			{
				methodGaussSeidel(A, B, X);
			}
			cout << "obliczona macierz X:\n";
			printMatrix(X);
		}
		else
		{
			double epsilon = 0.01;

			Matrix *cpyX = newMatrix(X->rows, X->columns);

			cout << "Podaj dokladnosc\n";
			cin >> epsilon;
			int iteration = 0;
			bool loop_continue = true;
			while (loop_continue)
			{
				iteration++;
				copyMatrix(X, cpyX);

				methodGaussSeidel(A, B, X);
				for (size_t i = 0; i < cpyX->rows; i++)
				{
					double x = abs(cpyX->elements[i][0] - X->elements[i][0]);
					if (x <+ epsilon)
					{
						loop_continue = false;
					}
				}
			}
			cout << "iteracje: " << iteration << "\n";
			cout << "obliczona macierz X:\n";
			printMatrix(X);
		}
	}

	cout << endl;
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	return 0;
}