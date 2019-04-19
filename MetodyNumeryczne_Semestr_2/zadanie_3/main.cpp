#include <iostream>
#include "mathFunctions.hpp"
#include "mathFunctionsList.hpp"
#include "interpolation.hpp"
#include "gnuplot.hpp"
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	mathFunction::functionMeta f;
	mathFunction::selectFunction(f);

	double searchedX;
	int nodes;
	vector <Point> points;

	cout << "Wska� liczb� w�z��w interpolacji:\n";
	cin >> nodes;

	chebyshevNodes(f.func, points, nodes);

	cout << "Argument x dla, kt�rego warto�� ma zosta� poszukana: \n";
	cin >> searchedX;

	double value = interpolation(points, searchedX, nodes);

	cout << "Interpolowana warto�� funkcji to:" << value << '\n';

	return 0;
	cin.get();
	cin.get();
	cin.get();
}