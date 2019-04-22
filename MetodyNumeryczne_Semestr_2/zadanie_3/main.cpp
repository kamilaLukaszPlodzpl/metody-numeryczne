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

	cout << "Wskaz liczbe wezlow inerpolacji:\n";
	cin >> nodes;

	chebyshevNodes(f.func, points, nodes);

	cout << "Argument x dla, ktorego wartosc ma zostac poszukana: \n";
	cin >> searchedX;

	double value =0;
	interpolation(points, searchedX, value);

	cout << "Interpolowana wartoœæ funkcji to:" << value << '\n';

	return 0;
	cin.get();
	cin.get();
	cin.get();
}