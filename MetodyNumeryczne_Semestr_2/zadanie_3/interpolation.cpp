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
		cout << "weze³ x" << point.x << " Wartosc y:" << point.y << '\n';
	}
}

void interpolation( const vector <Point> &points, double searchX, double &value ) {
	double produce;
	for (int i = 0; i < points.size(); i++) {
		produce = 1.0;
		for (int j = 0; j < points.size(); j++) {
			if (j != i) {
				produce *= ( (searchX - points[j].x) / (points[i].x - points[j].x) );
				cout << "Wspolczynnik l:" << produce << '\n';
			}
		}
		value += points[i].y * produce;
		cout << "Warstosc interpolowna:" << value << '\n';
	}
}
