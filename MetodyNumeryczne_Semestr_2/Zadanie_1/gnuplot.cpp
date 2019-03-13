#pragma once
#include "gnuplot.hpp"
#include <fstream>
#include <vector>
using namespace std;
namespace gnuplot
{

	void generateScript(
		const char *fileName,
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b
	) {

		vector<point> points;
		for (double i = a; i <= b; i += resolution)
		{
			point a;
			a.x = i;
			a.y = metaF.func(i);
			points.push_back(a);
		}

		fstream script(fileName, ios::out);

		script << "set terminal pngcairo\n";
		script << "set output \""<<fileName<<".png\"\n";
		script << "set xlabel \"x\"\n";
		script << "set ylabel \"y\"\n";
		script << "set title \"f(x)="<< metaF.name <<"\"\n";
		script << "set xrange [ " << a << " : " << b << " ]\n";
		script << "set yrange [ " << -10 << " : " << 10 << " ]\n";
		script << "set mxtics 5\n";
		script << "set mytics 5\n";
		script << "set xtics 1\n";
		script << "set ytics 1\n";

		script << "plot \"-\" with lines title \"title1\", \"-\" with lines title \"title2\"\n";

		for (size_t i = 0; i < points.size(); i++)
		{
			script << points[i].x << " " << points[i].y << "\n";
		}
		//script << "\n";
		//script << "1 3\n2 2\n3 1\n\n";
		script << "e\n";
		script << "1 3\n2 2\n3 1\n\n";

		script.close();
	}


}