#include "mathFunctionsList.hpp"
#include <cmath>
namespace mathFunctionList
{
	double same(double x) {// f(x)=x
		return x;
	}
	
	double Polynomial_1(double x) {// 4x^3+2x^2+x-5
		return 4 * (x*x*x) + 2 * (x*x) + x - 5;
	}

	double Polynomial_2(double x) {// x^2+x-3
		return x*x + x - 3;
	}

	double Trygonometric_1(double x) {// 4sin(2x)
		return 4 * sin(2 * x);
	}

	double Exponetial_1(double x) {// e^x-1
		return exp(x)-1;
	}

	double Polynomial_3(double x)// x^3+2x^2-2x+1
	{
		return (x*x*x) + (2 * x*x) - (2 * x) + 1;
	}

	double aaa(double x)// sin(x)-3^x
	{
		return sin(x) - pow(3,x);
	}

	double bbb(double x)//cos(log(x))*(sin(x))^2
	{
		return cos(log(x))*sin(x)*sin(x);
	}

	double ccc(double x)// 2cos(x)
	{
		return 2 * cos(x);
	}

}