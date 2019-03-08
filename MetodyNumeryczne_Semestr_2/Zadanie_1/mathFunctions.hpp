#pragma once
#include <string>
#include <vector>

namespace mathFunction
{
	typedef double(*function)(double);

	double superposition(function f, function g, double x);//Oblicza f(g(x))

	struct functionMeta;

	void registerFunction(function func, std::string name);

	std::vector<functionMeta> list(0);
}
//double samplePolynomial(double x);//Wielomian
//double sampleTrigonometric(double x);//Trygonometryczna
//double sampleExponent(double x);//Wyk³adnicza
