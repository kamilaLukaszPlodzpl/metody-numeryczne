#include <iostream>
#include "newtonMethod.hpp"
#include <cmath>

using namespace std;

double newtonA(mathFunction::function func, mathFunction::function derivative, double a, double b, double epsilon, int &iteration) {//metoda stycznych
	if (func(a) * func(b) > 0) {
		cout << "Function doesn't meet essential assumptions";
		return NULL; 
	}
	double firstX;
	cout << "Starting x =";
	cin >> firstX;

	while (abs(func(firstX)) <= epsilon) {
	// while( abs(x0 - currentX) <= std::numeric_limits<double>::epsilon()) - inny warunek stopu
		double tempX = firstX - (func(firstX)/derivative(firstX));
		firstX = tempX;
		iteration++;
	}
	return firstX;
}

double newtonB(mathFunction::function func, mathFunction::function derivative, double a, double b, double &epsilon, int iteration) {
	if ( func(a) * func(b) > 0 ) {
		cout << "Function doesn't meet essential assumptions";
		return NULL;
	}
	int i = 0;

	double firstX;
	cout << "Starting x =";
	cin >> firstX;


	while (i <= iteration) {
		double tempX = firstX - ( func(firstX) / derivative(firstX) );
		firstX = tempX;
		iteration++;
	}
	//epsilon = abs( 0 - func(x) ); dok³adnoœæ przybli¿enia do 0
	return firstX;
}