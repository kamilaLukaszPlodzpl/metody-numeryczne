#include <iostream>
#include "bisectionMetod.hpp"
#include <cmath>

using namespace std;

//* Kamila
double bisectionA(mathFunction::function func, double a, double b, double E, int &iteration) {
	if ((func(a)) * (func(b)) > 0) {
		cout << "Function doesn't meet essential assumptions"; // wartosc funkcji na krancach przedzialu musi miev rozne znaki
		return NULL;
	}
	double x = 0;
	while (abs(a - b) > E) {
		iteration++;
		x = (a + b) / 2;
		if (abs(func(x)) < E) {
			return x;
		}
		if (func(x)*(func(a)) < 0) {
			b = x;
		}
		else {
			a = x;
		}
		//cout << x << iteration;
	}
	return x;
}
//*/

/* £ukasz
double bisectionA(mathFunction::function func, double a, double b, double epsilon, int &iteration) {
	if (func(a)*func(b) >= 0) {
		cout << "Error, f(" << a << ") * f(" << b << ") >= 0. f(a)*f(b) must be less than zero!" << endl;
		iteration = -1;
		return NULL;
	}
	iteration = 1;
	while (abs(a-b) > epsilon) {
		double x1 = (a + b) / 2;
		if (abs(func(x1)) < epsilon)
			return x1;

		if ((func(a) * func(x1)) < 0) {
			b = x1;
		}
		else {
			a = x1;
		}
		iteration++;
	}
	double x1 = (a + b) / 2;
	return x1;
}
//*/
double bisectionB(mathFunction::function func, double a, double b, double E, int &iteration) {
	if ((func(a)) * (func(b)) > 0) {
		cout << "Function doesn't meet essential assumptions";
		return NULL;
	}
	double x = 0;
	int i = 0;
	while (i < iteration) {
		i++;
		x = (a + b) / 2;
		if (func(x)*(func(a)) < 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	//E = abs( 0 - func(x) ); dok³adnoœæ przybli¿enia do 0
	return x;
}

