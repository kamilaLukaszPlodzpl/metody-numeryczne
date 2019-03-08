#include <iostream>
#include "newtonMethod.hpp"
#include "mathFunctions.hpp"

using namespace std;

double newtonMetod(double a, double b, double x0, mathFunction::function func) {
	double derivative; // trzeba wpisac wartosc pochodnej
	if (func(a) * func(b) < 0) {
		cout << "Function doesn't meet essential assumptions";
		return;
	}
	if (derivative == 0) {
		cout << "Function doesn't meet essential assumptions";
		return;
	}
	while ()



}