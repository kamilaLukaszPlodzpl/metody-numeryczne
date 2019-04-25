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

	gnuplot::script *script = gnuplot::initializeScript();
	ofstream out("script.plt");
	ofstream out1("script1.plt");

	double searchedX = 0.5;
	int nodes = 100;
	vector <gnuplot::point> points;

	cout << "Wskaz liczbe wezlow inerpolacji:\n";
	//cin >> nodes;


	chebyshevNodes(f.func, points, nodes);//chebyshevNodes generation
	gnuplot::plot(script, f, points.front().x, points.back().x, 0.001);
	gnuplot::plot(script, points, "chebysevNodes", false);
	
	points.erase(points.begin());

	cout << "Argument x dla, ktorego wartosc ma zostac poszukana: \n";
	//cin >> searchedX;

	double value = 0;

	vector<gnuplot::point> interpolatedPoints;
	for (double x = script->minX; x <= script->maxX; x+=0.1)
	{
		gnuplot::point p;
		p.x = x;
		double a;
		interpolation(points, p.x,a);
		p.y = a;
		interpolatedPoints.push_back(p);
	}

	//interpolation(points, searchedX, value);
	//cout << "Interpolowana wartoœæ funkcji to:" << value << '\n';
	//gnuplot::point i;
	//i.x = searchedX;
	//i.y = value;
	gnuplot::save(script, out);
	gnuplot::plot(script, interpolatedPoints, "interpolated", true);
	//gnuplot::plot(script, i, "interpolated");
	gnuplot::save(script, out1);
	out.close();
	out1.close();

	cin.get();
	cin.get();
	cin.get();
	return 0;
}