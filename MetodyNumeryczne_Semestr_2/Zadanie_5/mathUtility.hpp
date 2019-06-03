#pragma once
#include <vector>
#include "mathFunctions.hpp"
#include "gnuplot.hpp"
namespace math
{

	struct Node
	{
		double value;
		double weight;
	};
	double horner(vector<double> a, double x);
	double hermitePolynominal(unsigned int i, double x);
	inline int factorial(int n);
	inline int power(int x, int y);



	double aproximationHermite(mathFunction::function f, int approxSteps, int integralNodes, double x);
	double aproximationHermiteFactor(mathFunction::function f, int n, int k);
	double integralGaussaHermite(mathFunction::function f, int nodesNumber, int approxStep);
	std::vector<Node> hermiteZeroPlaces(int n);
}