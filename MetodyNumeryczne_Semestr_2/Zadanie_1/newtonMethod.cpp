#include <iostream>
#include "newtonMethod.hpp"
#include <cmath>

using namespace std;

double newtonA(mathFunction::function func, mathFunction::function derivative, double a, double b, double epsilon, int &iteration) {//metoda stycznych
	if (func(a) * func(b) > 0) {
		cout << "Error, f(" << a << ") * f(" << b << ") >= 0. f(a)*f(b) must be less than zero!\n";
		return NULL; 
	}

	double nextX = 0;
	double currentX = b;

	while (abs(currentX - nextX) >= epsilon) {
		iteration++;
		if (abs(func(currentX)) <= epsilon) {
			return currentX;
		}
		double nextX = currentX - (func(currentX)/derivative(currentX));
		currentX = nextX;
	}
	return currentX;
}

double newtonB(mathFunction::function func, mathFunction::function derivative, double a, double b, double &epsilon, int iteration) {
	if (func(a) * func(b) > 0) {
		cout << "Error, f(" << a << ") * f(" << b << ") >= 0. f(a)*f(b) must be less than zero!\n";
		return NULL;
	}
	int i = 0;

	double currentX = b;
	double nextX = 0;

	while (i <= iteration) {
		double nextX = currentX - (func(currentX) / derivative(currentX));
		 currentX = nextX;
		i++;
	}
	// dok³adnoœæ obliczeñ epsilon=
	return currentX;
}