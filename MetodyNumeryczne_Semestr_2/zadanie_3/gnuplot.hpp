#pragma once
#include <string>
#include <fstream>
#include "mathFunctions.hpp"

using namespace std;

namespace gnuplot
{

	struct point
	{
		double x, y;
	};
	struct dataPlot
	{
		bool asLine;
		string label;
		vector<point> points;
	};
	struct script {
		double minX, maxX;
		double minY, maxY;
		int xTic, yTic;
		int mxTic, myTic;
		vector<dataPlot *> dataPlots;
	};

	script *initializeScript();
	dataPlot *initializeDataPlot(string label = "", bool asLine = false);
	void plot(script *script, const vector<point> &points, string label, bool asLine);
	void plot(script *script, const mathFunction::functionMeta &func, double a, double b, double resolution);
	void plot(script *script, point point, string label);
	void save(const script *script, ostream &stream);
}