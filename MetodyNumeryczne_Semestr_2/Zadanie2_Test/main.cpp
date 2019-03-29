#define LIST_FILE_NAME "list.txt"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../Zadanie_2/matrix.hpp"
#include "../Zadanie_2/methodGauss-Seidel.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream listFile(LIST_FILE_NAME);
	string pathDir;
	listFile >> pathDir;
	vector<string> list;
	while (!listFile.eof())
	{
		string a;
		listFile >> a;
		list.push_back(a);
	}

	for (size_t i = 0; i < list.size(); i++)
	{
		cout << "########################################\n";
		string fileName = pathDir + list[i];

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
		for(int i = 0; i < 10; i++)
			formulaFromWiki(A, B, X);
		cout << "obliczona macierz X:\n";
		printMatrix(X);
	}

	cin.get();
	cin.get();
}