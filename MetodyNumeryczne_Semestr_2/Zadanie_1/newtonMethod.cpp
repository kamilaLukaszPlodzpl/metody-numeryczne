#include <iostream>
#include "newtonMethod.hpp"
#include <cmath>

using namespace std;

double newtonMetod(double a, double b, double x0, mathFunction::function func) {
	double derivative; // trzeba wpisac wartosc pochodnej
	if (func(a) * func(b) < 0 || derivative == 0) {
		cout << "Function doesn't meet essential assumptions";
		return NULL; 
	}
	double x = x0 - (func(x0) - derivative);
	while (abs(func(x)) <= std::numeric_limits<double>::epsilon()) { 
	// while( abs(x0 - currentX) <= std::numeric_limits<double>::epsilon()) - inny warunek stopu
		double tempX = x - (func(x) - derivative); //pochodna w punkcie currentX
		x = tempX;
	}
	return x;
}