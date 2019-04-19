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

	cout << "Wska¿ liczbê wêz³ów interpolacji:\n";
	cin >> nodes;

	chebyshevNodes(f.func, points, nodes);

	cout << "Argument x dla, którego wartoœæ ma zostaæ poszukana: \n";
	cin >> searchedX;

	double value = interpolation(points, searchedX, nodes);

	cout << "Interpolowana wartoœæ funkcji to:" << value << '\n';

	return 0;
	cin.get();
	cin.get();
	cin.get();
}