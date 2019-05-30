#pragma once
#include <vector>
#include "mathFunctions.hpp"
namespace math
{
	double simsonFormula(mathFunction::function f, double a, double b);
	double integralNewtonCotes(mathFunction::function f, double step, double a, double b);
	double integralNewtonCotesInfinite(mathFunction::function f, double step, double epsilon);
	double integralGaussaHermite(mathFunction::function f, int nodesNumber);
	std::vector<double> hermiteZeroPlaces(int n);
	double limit(mathFunction::function f, double x, bool &exist);
}