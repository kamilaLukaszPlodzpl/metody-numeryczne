#include <iostream>
#include "newtonMethod.hpp"
#include <cmath>

using namespace std;

double newtonA(mathFunction::function func, double a, double b, double x, double E, int &iteration) {
	if (func(a) * func(b) > 0) {
		cout << "Function doesn't meet essential assumptions";
		return NULL; 
	}
	while (abs(func(x)) <= E) { 
		double derivative = 0;
		cout << "Pochodna w punkcie x=" << x << ':\n';
		cin >> derivative;
	// while( abs(x0 - currentX) <= std::numeric_limits<double>::epsilon()) - inny warunek stopu
		double tempX = x - (func(x)/derivative);
		x = tempX;
		iteration++;
	}
	return x;
}

double newtonB(mathFunction::function func, double a, double b, double x, double E, int &iteration) {
	if ( func(a) * func(b) > 0 ) {
		cout << "Function doesn't meet essential assumptions";
		return NULL;
	}
	int i = 0;
	double derivative = 0;
	cout << "Pochodna w punkcie x=" << x << ':\n';
	cin >> derivative;
	while (i <= iteration) {
		double tempX = x - ( func(x) / derivative );
		x = tempX;
		iteration++;
	}
	//E = abs( 0 - func(x) ); dok³adnoœæ przybli¿enia do 0
	return x;
}