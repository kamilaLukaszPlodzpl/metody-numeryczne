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
	int nodes = 40;
	
	vector <gnuplot::point> points;

	//cout << "Wskaz liczbe wezlow inerpolacji:\n";
	//cin >> nodes;
	double a = -100;
	double b = 100;
	nodes++;
	chebyshevNodes(f.func, points, nodes,a,b);//chebyshevNodes generation
	gnuplot::plot(script, f, points.front().x, points.back().x, 0.001);
	gnuplot::plot(script, points, "chebysevNodes", false);
	
	points.erase(points.begin());

	//cout << "Argument x dla, ktorego wartosc ma zostac poszukana: \n";
	//cin >> searchedX;

	double value = 0;

	vector<gnuplot::point> interpolatedPoints;
	for (double x = a; x <= b; x+=0.001)
	{
		gnuplot::point p;
		p.x = x;
		p.y = interpolation(points, p.x);
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