#include <iostream>
#include "bisectionMetod.hpp"
#include <cmath>

using namespace std;

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
		a = x;
		//cout << x << iteration;
	}
	return x;
}

double bisectionB(mathFunction::function func, double a, double b, double E, int &iteration) {
	if ((func(a)) * (func(b)) > 0) {
		cout << "Function doesn't meet essential assumptions"; // wartosc funkcji na krancach przedzialu musi miec rozne znaki
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
		a = x;
		//cout << x << iteration;
	}
	// To do : obliczanie dokladnosci E= 
	return x;
}