#include "mathFunctionsList.hpp"
#include <cmath>
namespace mathFunctionList
{
	double same(double x) {// f(x)=x
		return x;
	}

	double f1(double x) {// f(x)=abs(10/x)
		return abs((double)10 / x);
	}
	double f2(double x) {// f(x)=-abs(0.01*x)+1
		return -abs(0.01*x)+1;
	}
	double f3(double x) {// f(x)=x^2+3
		return (x*x) + 3;
	}
	double f4(double x) {// f(x)=exp(-x-x^2)
		return exp(-x - (x*x));
	}
}