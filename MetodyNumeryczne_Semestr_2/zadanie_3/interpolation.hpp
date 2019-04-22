#pragma once
#include <iostream>
#include <vector>
#include "mathFunctions.hpp"

using namespace std;

struct Point {
	double x;
	double y;
};

void chebyshevNodes(mathFunction::function function, vector <Point> &points, int nodes);
void interpolation(const vector <Point> &points, double searchX, double &value);