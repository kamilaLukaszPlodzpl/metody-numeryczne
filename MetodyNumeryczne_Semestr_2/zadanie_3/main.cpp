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

	double searchedX = 14;
	int nodes = 10;
	vector <gnuplot::point> points;

	cout << "Wskaz liczbe wezlow inerpolacji:\n";
	//cin >> nodes;
	double a = 1;
	double b = 6;

	chebyshevNodes(f.func, points, nodes,a,b);//chebyshevNodes generation
	gnuplot::plot(script, f, points.front().x, points.back().x, 0.001);
	gnuplot::plot(script, points, "chebysevNodes", false);
	
	//cout << "Argument x dla, ktorego wartosc ma zostac poszukana: \n";
	//cin >> searchedX;
	
	double value = interpolation( points, searchedX );
	//cout << "Interpolowana wartoœæ funkcji to:" << value << '\n';
	gnuplot::point i;
	i.x = searchedX;
	i.y = value;
	gnuplot::save(script, out);
	gnuplot::plot(script, i, "interpolated");
	gnuplot::save(script, out1);
	out.close();
	out1.close();

	cin.get();
	cin.get();
	cin.get();
	return 0;
}