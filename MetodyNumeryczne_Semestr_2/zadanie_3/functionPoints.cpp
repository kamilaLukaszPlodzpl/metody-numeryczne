#include <iostream>
#include <vector>
#include "mathFunctions.hpp"
#include "mathFunctionsList.hpp"
#include "functionPoints.hpp"
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

void functionValues( mathFunction::function function, vector <Point> &points, int nodes ) { //generacja wêz³ów
	points.clear();

	for(int i =0; i < nodes; i++){
		Point point;
		point.x = cos(((2 * i - 1) / (double)(2 * nodes)) * M_PI);
		point.y = function(point.x);
		points.push_back(point);
	}
}

void interpolationPolynomial(const vector <Point> &point) {

}
