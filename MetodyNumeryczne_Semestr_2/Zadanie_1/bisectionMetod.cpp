#include <iostream>
#include "bisectionMetod.hpp"
#include "mathFunctions.hpp"

using namespace std;

double bisection(double a, double b, mathFunction::function func) {
	double result_a = func(a);
	double result_b = func(b);
	if ((result_a * result_b) > 0) {
		cout << "Function doesn't meet essential assumptions"; // wartosc funkcji na krancach przedzialu musi miev rozne znaki
		return;
	}
	double current_x;
	double result_x;
	while (abs(a - b) < std::numeric_limits<double>::epsilon()) { 
		current_x = (a - b) / 2;
		result_x = func(current_x);
		if (abs(result_x) < std::numeric_limits<double>::epsilon()) {
			return current_x;
		}
		if (result_a * result_x < 0) {
			b = current_x;
		}
		a = current_x;
	}
	return current_x;
}