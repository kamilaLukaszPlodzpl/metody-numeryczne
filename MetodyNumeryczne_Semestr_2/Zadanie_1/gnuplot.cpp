#pragma once
#include "gnuplot.hpp"
#include <fstream>
#include <vector>
#include <climits>
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
		double minY = 0, maxY = 0;
		for (double i = a; i <= b; i += resolution)
		{
			point a;
			a.x = i;
			a.y = metaF.func(i);
			if (a.y < minY)
				minY = a.y;
			else if (a.y > maxY)
				maxY = a.y;

			points.push_back(a);
		}

		fstream script(fileName, ios::out);

		script << "set terminal pngcairo\n";
		script << "set output \""<<fileName<<".png\"\n";
		//script << "set xlabel \"x\"\n";
		//script << "set ylabel \"y\"\n";
		//script << "set title \"\"\n";
		script << "set xrange [ " << a << " : " << b << " ]\n";
		script << "set yrange [ " << minY << " : " << maxY << " ]\n";
		script << "set mxtics 5\n";
		script << "set mytics 5\n";
		script << "set xtics 1\n";
		script << "set ytics 1\n";

		script << "plot \"-\" with lines title \"f(x)="<<metaF.name<<"\", 0 \n";

		for (size_t i = 0; i < points.size(); i++)
		{
			script << points[i].x << " " << points[i].y << "\n";
		}

		//script << "plot f(x)=x, f(x)\n";

		script << "\n";
		script.close();
	}


}