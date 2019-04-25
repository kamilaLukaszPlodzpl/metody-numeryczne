#include <iostream>
#include <vector>
#include "mathFunctions.hpp"
#include "mathFunctionsList.hpp"
#include "interpolation.hpp"
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

void chebyshevNodes( mathFunction::function function, vector <gnuplot::point> &points, int nodes, double a, double b ) { //generacja wêz³ów
	points.clear();

	for(int i = 0; i < nodes; i++){
		gnuplot::point point;
		double cosinus = cos(((double)(2 * i - 1) / (double)(2 * nodes)) * M_PI);
		point.x = 0.5 * ( ( a + b ) + ( ( b -a ) * cosinus ) );
		point.y = function(point.x);
		points.push_back(point);
		//cout << "wezel x " << point.x << " Wartosc y:" << point.y << '\n';
	}
}

double interpolation( const vector <gnuplot::point> &points, double searchX ) {
	double value = 0;
	for (int i = 0; i < points.size(); i++) {
		double produce = 1.0;
		for (int j = 0; j < points.size(); j++) {
			if (j != i) {
				//cout << "//////////////////////////\n";
				//cout << "iterator j " << j << '\n';
				//cout << "i (" <<points[i].x<< " ; " << points[i].y << ")\n";
				//cout << "j (" << points[j].x << " ; " << points[j].y << ")\n";
				//cout << (searchX - points[j].x) <<"/"<< (points[i].x - points[j].x) <<"="  << ((searchX - points[j].x) / (points[i].x - points[j].x)) << '\n';
				produce *= ( (searchX - points[j].x) / (points[i].x - points[j].x) );
				//cout << "Wspolczynnik l:" << produce << '\n';
			}
		}
		value += points[i].y * produce;
		//cout << "Warstosc interpolowna:" << value << '\n';
	}
	return value;
}
