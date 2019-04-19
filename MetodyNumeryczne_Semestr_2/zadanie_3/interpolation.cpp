#include <iostream>
#include <vector>
#include "mathFunctions.hpp"
#include "mathFunctionsList.hpp"
#include "interpolation.hpp"
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

void chebyshevNodes( mathFunction::function function, vector <Point> &points, int nodes ) { //generacja wêz³ów
	points.clear();

	for(int i =0; i < nodes; i++){
		Point point;
		point.x = cos(((2 * i - 1) / (double)(2 * nodes)) * M_PI);
		point.y = function(point.x);
		points.push_back(point);
	}
}

double interpolation( const vector <Point> &points, double searchX, int nodes ) {
	double value = 0;
	for (int i = 0; i < nodes; i++) {
		double produce = 1;
		for (int j = 0; j < nodes; j++) {
			if (j != i) {
				produce *= ((searchX - points[i].x) / (points[i].x - points[j].x));
			}
		}
		value += points[i].y * produce;
	}
	return value;
}
