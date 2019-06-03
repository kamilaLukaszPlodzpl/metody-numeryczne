#pragma once
#include "gnuplot.hpp"
#include <fstream>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

namespace gnuplot
{
	dataPlot *initializeDataPlot(string label, bool asLine)
	{
		gnuplot::dataPlot* d = new dataPlot;
		d->asLine = asLine;
		d->label = label;
		return d;
	}
	script *initializeScript()
	{
		script *s = new script;
		s->minX = -1;
		s->maxX = 1;
		s->minY = -1;
		s->maxY = 1;
		s->xTic = 1;
		s->yTic = 1;
		s->mxTic = 5;
		s->myTic = 5;
		return s;
	}

	void plot(script *script, vector<point> &points, string label, bool asLine)
	{
		dataPlot *d = initializeDataPlot(label, asLine);
		for (size_t i = 0; i < points.size(); i++)
		{
			d->points.push_back(points[i]);
			if (points[i].x > script->maxX)
				script->maxX = points[i].x;
			else if (points[i].x < script->minX)
				script->minX = points[i].x;
			if (points[i].y > script->maxY)
				script->maxY = points[i].y;
			else if (points[i].y < script->minY)
				script->minY = points[i].y;
		}
		script->dataPlots.push_back(d);
	}

	void plot(script *script, point point, string label)
	{
		dataPlot *d = initializeDataPlot(label, false);

		if (point.x > script->maxX)
			script->maxX = point.x;
		else if (point.x < script->minX)
			script->minX = point.x;
		if (point.y > script->maxY)
			script->maxY = point.y;
		else if (point.y < script->minY)
			script->minY = point.y;

		d->points.push_back(point);
		script->dataPlots.push_back(d);
	}

	void save(const script *script, ostream &stream)
	{

		//if (renderToFile)
		//{
		//	script << "set terminal pngcairo\n";
		//	script << "set output \"" << fileName << ".png\"\n";
		//}
		//script << "set xlabel \"x\"\n";
		//script << "set ylabel \"y\"\n";
		//script << "set title \"\"\n";
		stream << "set xzeroaxis\n" << "set yzeroaxis\n";
		stream << "set xrange [ " << script->minX << " : " << script->maxX << " ]\n";
		stream << "set yrange [ " << script->minY << " : " << script->maxY << " ]\n";
		stream << "set mxtics "<< script->mxTic <<"\n";
		stream << "set mytics " << script->myTic << "\n";
		stream << "set xtics " << script->xTic << "\n";
		stream << "set ytics " << script->xTic << "\n";

		//plot "-" with lines title "f(x)="  \n;
		stream << "plot ";
		for (size_t i = 0; i < script->dataPlots.size(); i++)
		{
			dataPlot *d = script->dataPlots[i];
			stream << "\"-\" ";
			if (d->asLine)
			{
				stream << "with lines ";
			}
			stream << "title \"" << d->label << "\"";
			if (i + 1 < script->dataPlots.size())
			{
				stream << ", ";
			}
		}
		stream << "\n";
		for (size_t i = 0; i < script->dataPlots.size(); i++)
		{
			gnuplot::dataPlot *d = script->dataPlots[i];
			for (size_t p = 0; p < d->points.size(); p++)
			{
				stream << d->points[p].x << " " << d->points[p].y << "\n";
			}
			if (i + 1 < script->dataPlots.size())
			{
				stream << "e\n";
			}
		}
		stream << "\n";
	}
	/*
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

	}//*/
}