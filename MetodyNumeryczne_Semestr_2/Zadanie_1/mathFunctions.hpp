#pragma once
#include <string>
#include <vector>

namespace mathFunction
{
	typedef double(*function)(double);

	double superposition(function f, function g, double x);//Oblicza f(g(x))

	struct functionMeta {
		function func;
		function derivativeFunc;
		std::string name;
	};

	typedef std::vector<functionMeta> functionMetaArr;

	functionMeta createFunctionMeta();

	functionMeta createFunctionMeta(function func, std::string name);

	void selectFunction(functionMeta &f, functionMeta &g);

	void selectFunction(functionMeta &f);

	functionMetaArr getFunctions();

}
//double samplePolynomial(double x);//Wielomian
//double sampleTrigonometric(double x);//Trygonometryczna
//double sampleExponent(double x);//Wyk³adnicza
