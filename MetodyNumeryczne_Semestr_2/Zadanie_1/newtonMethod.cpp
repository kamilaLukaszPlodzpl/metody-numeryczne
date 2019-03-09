#include <iostream>
#include "newtonMethod.hpp"
#include <cmath>

using namespace std;

double newtonMetod(mathFunction::function func, double a, double b, double x, int &iteration) {
	double derivative = 1; // trzeba wpisac wartosc pochodnej, ustawione na 1 bo nie kompiluje sie ale do poprawy
	if (func(a) * func(b) < 0 || derivative == 0) {
		cout << "Function doesn't meet essential assumptions";
		return NULL; 
	}
	while (abs(func(x)) <= std::numeric_limits<double>::epsilon()) { 
	// while( abs(x0 - currentX) <= std::numeric_limits<double>::epsilon()) - inny warunek stopu
		double tempX = x - (func(x) - derivative); //pochodna w punkcie trzeba poprawic
		x = tempX;
		iteration++;
	}
	return x;
}