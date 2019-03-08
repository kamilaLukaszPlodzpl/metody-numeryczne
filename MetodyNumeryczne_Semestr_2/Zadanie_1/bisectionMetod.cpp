#include <iostream>
#include "bisectionMetod.hpp"
#include "mathFunctions.hpp"

using namespace std;

double bisection(double a, double b, mathFunction::function func) {
	if ((func(a)) * (func(b)) > 0) {
		cout << "Function doesn't meet essential assumptions"; // wartosc funkcji na krancach przedzialu musi miev rozne znaki
		return;
	}
	double x = 0;
	while (abs(a - b) > std::numeric_limits<double>::epsilon()) {
		x = (a + b) / 2;
		if (abs(func(x)) < std::numeric_limits<double>::epsilon()) {
			return x;
		}
		if (func(x)*(func(a)) < 0) {
			b = x;
		}
		a = x;
	}
	return x;
}