#include <iostream>
#include "bisectionMetod.hpp"
#include <cmath>

using namespace std;

double bisectionA(mathFunction::function func, double a, double b, double epsilon, int &iteration) {
	if ((func(a)) * (func(b)) > 0) {
		cout << "Error, f(" << a << ") * f(" << b << ") >= 0. f(a)*f(b) must be less than zero!\n";
		return NULL;
	}
	double x = 0;
	while (abs(a - b) > epsilon) {
		iteration++;
		x = (a + b) / 2;
		if (abs(func(x)) < epsilon) {
			return x;
		}
		if (func(x)*(func(a)) < 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	x = (a + b) / 2;
	return x;
}

double bisectionB(mathFunction::function func, double a, double b, double &epsilon, int iteration) {
	if ((func(a)) * (func(b)) > 0) {
		cout << "Error, f(" << a << ") * f(" << b << ") >= 0. f(a)*f(b) must be less than zero!\n";
		return NULL;
	}
	double x = 0;
	int i = 0;
	while (i < iteration) {
		x = (a + b) / 2;
		if (func(x)*(func(a)) < 0) {
			b = x;
		}
		else {
			a = x;
		}
		i++;
	}
	x = (a + b) / 2;
	//epsilon = 
	return x;
}

