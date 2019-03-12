#include <iostream>
#include "newtonMethod.hpp"
#include <cmath>

using namespace std;

double newtonA(mathFunction::function func, mathFunction::function derivative, double a, double b, double epsilon, int &iteration) {//metoda stycznych
	if (func(a) * func(b) > 0) {
		cout << "Error, f(" << a << ") * f(" << b << ") >= 0. f(a)*f(b) must be less than zero!\n";
		return NULL; 
	}

	double firstX;
	cout << "Starting x =";
	cin >> firstX;

	double nextX = 0;

	while (abs(firstX - nextX) >= epsilon) {
		iteration++;
		if (abs(func(firstX)) <= epsilon) {
			return firstX;
		}
		double nextX = firstX - (func(firstX)/derivative(firstX));
		firstX = nextX;
	}
	return firstX;
}

double newtonB(mathFunction::function func, mathFunction::function derivative, double a, double b, double &epsilon, int iteration) {
	if (func(a) * func(b) > 0) {
		cout << "Error, f(" << a << ") * f(" << b << ") >= 0. f(a)*f(b) must be less than zero!\n";
		return NULL;
	}
	int i = 0;

	double firstX;
	cout << "Starting x =";
	cin >> firstX;

	double nextX = 0;

	while (i <= iteration) {
		double nextX = firstX - (func(firstX) / derivative(firstX));
		firstX = nextX;
		i++;
	}
	// dok³adnoœæ obliczeñ epsilon=
	return firstX;
}