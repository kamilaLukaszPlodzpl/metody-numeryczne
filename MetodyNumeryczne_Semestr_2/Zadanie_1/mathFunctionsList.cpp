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
}