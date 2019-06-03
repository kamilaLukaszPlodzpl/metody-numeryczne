#pragma once
#include <string>
#include <fstream>
#include <vector>

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
		std::string label;
		std::vector<gnuplot::point> points;
	};
	struct script {
		double minX, maxX;
		double minY, maxY;
		int xTic, yTic;
		int mxTic, myTic;
		std::vector<dataPlot *> dataPlots;
	};

	script *initializeScript();
	dataPlot *initializeDataPlot(string label = "", bool asLine = false);
	void plot(script *script, vector<point> &points, string label, bool asLine);
	void plot(script *script, point point, string label);
	void save(const script *script, ostream &stream);
}