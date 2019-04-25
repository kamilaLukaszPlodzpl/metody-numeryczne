#pragma once
#include <iostream>
#include <vector>
#include "gnuplot.hpp"
#include "mathFunctions.hpp"

using namespace std;


void chebyshevNodes(mathFunction::function function, vector <gnuplot::point> &points, int nodes, double a, double b);
double interpolation(const vector <gnuplot::point> &points, double searchX);
