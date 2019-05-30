#pragma once
#include <vector>
#include "mathFunctions.hpp"
namespace math
{
	struct Node
	{
		double value;
		double weight;
	};
	double simsonFormula(mathFunction::function f, double a, double b);
	double integralNewtonCotes(mathFunction::function f, double epsilon, double a, double b, int &iterations);
	double integralNewtonCotesInfinite(mathFunction::function f, double epsilon, double &a, double &b, int &iterations);
	double integralGaussaHermite(mathFunction::function f, int nodesNumber);
	std::vector<Node> hermiteZeroPlaces(int n);
	double limitPlusInf(mathFunction::function f, double epsilon, bool &exist);
	double limitMinusInf(mathFunction::function f, double epsilon, bool &exist);
}