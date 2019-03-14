#pragma once
#include "gnuplot.hpp"
#include <fstream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cstdio>
using namespace std;
namespace gnuplot
{

	void generateScript(
		const char *fileName,
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b,
		bool renderToFile
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

		if (renderToFile)
		{
			script << "set terminal pngcairo\n";
			script << "set output \"" << fileName << ".png\"\n";
		}
		//script << "set xlabel \"x\"\n";
		//script << "set ylabel \"y\"\n";
		//script << "set title \"\"\n";
		script << "set xzeroaxis\n" << "set yzeroaxis\n";
		script << "set xrange [ " << a << " : " << b << " ]\n";
		script << "set yrange [ " << minY << " : " << maxY << " ]\n";
		script << "set mxtics 5\n";
		script << "set mytics 5\n";
		script << "set xtics 1\n";
		script << "set ytics 1\n";

		script << "plot \"-\" with lines title \"f(x)="<<metaF.name<<"\" \n";

		for (size_t i = 0; i < points.size(); i++)
		{
			script << points[i].x << " " << points[i].y << "\n";
		}

		script << "\n";
		script.close();

	}


	void generateScript(
		const char *fileName,
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b,
		bool renderToFile,
		double x1,
		const char *x1L,
		double x2,
		const char *x2L
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

		if (renderToFile)
		{
			script << "set terminal pngcairo\n";
			script << "set output \"" << fileName << ".png\"\n";
		}
		//script << "set xlabel \"x\"\n";
		//script << "set ylabel \"y\"\n";
		//script << "set title \"\"\n";
		script << "set xzeroaxis\n" << "set yzeroaxis\n";
		script << "set xrange [ " << a << " : " << b << " ]\n";
		script << "set yrange [ " << minY << " : " << maxY << " ]\n";
		script << "set mxtics 5\n";
		script << "set mytics 5\n";
		script << "set xtics 1\n";
		script << "set ytics 1\n";

		script << "plot \"-\" with lines title \"f(x)=" << metaF.name << "\""
			<< ", \"-\" with points linestyle 1 title \"" << x1L << "\""
			<< ", \"-\" with points linestyle 2 title \"" << x2L << "\""
			<< "\n";

		for (size_t i = 0; i < points.size(); i++)
		{
			script << points[i].x << " " << points[i].y << "\n";
		}

		script << "e\n";
		script << x1 << " " << metaF.func(x1) << "\n";
		script << "e\n";
		script << x2 << " " << metaF.func(x2) << "\n";

		script << "\n";
		script.close();

	}


	void displayFunction(
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b,
		bool saveToFile
	){
		if (saveToFile)
		{
			string name = metaF.name+".plt";
			generateScript(name.c_str(), resolution, metaF, a, b,true);
		}
		generateScript("temp.plt", resolution, metaF, a, b,false);
		system("temp.plt");
		remove("temp.plt");
	}


	void displayFunction(
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b,
		bool saveToFile,
		double x1,
		const char *x1L,
		double x2,
		const char *x2L
	) {
		if (saveToFile)
		{
			string name = metaF.name + ".plt";
			generateScript(name.c_str(), resolution, metaF, a, b, true,x1,x1L,x2,x2L);
		}
		generateScript("tempxx.plt", resolution, metaF, a, b,false, x1, x1L, x2, x2L);
		system("tempxx.plt");
		remove("tempxx.plt");
	}


}