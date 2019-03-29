#include <iostream>
#include "matrix.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	Matrix *m = readMatrix("./matrix/a.txt");
	printMatrix(m);
	cin.get();
	cin.get();
}