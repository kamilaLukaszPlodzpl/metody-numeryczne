#include "mathFunctionsList.hpp"
#include <cmath>
namespace mathFunctionList
{
	double same(double x) {// f(x)=x
		return x;
	}
	double derivative_same(double x) {
		return 1;
	}

	double Polynomial_1(double x) {// 4x^3+2x^2+x-5
		return 4 * (x*x*x) + 2 * (x*x) + x - 5;
	}
	double derivative_Polynomial_1(double x) {
		return 12*(x*x) + 4*x + 1;
	}

	double Polynomial_2(double x) {// x^2+x-3
		return x*x + x - 3;
	}
	double derivative_Polynomial_2(double x) {
		return 2*x+1;
	}

	double Trygonometric_1(double x) {// 4sin(2x)
		return 4 * sin(2 * x);
	}
	double derivative_Trygonometric_1(double x) {
		return 8 * cos(2 * x);
	}

	double Exponetial_1(double x) {// e^x
		return exp(x);
	}
	double derivative_Exponetial_1(double x) {
		return exp(x);
	}
}