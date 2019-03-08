#include <iostream>
#include "sampleMathFunctions.hpp"
using namespace std;

double bisection(double a, double b) {
	double E; //ten epsilon ale jeszcze nie wiem czym on jest
	double result_a = polynomial(a); //polynomial = przykladowa funkcja
	double result_b = polynomial(b);
	if ((result_a * result_b) > 0) {
		cout << "Function doesn't meet essential assumptions "; // wartoœæ funkcji na krañcach przedzia³u musi mieæ ró¿ne znaki
		return 1;
	}
	double current_x;
	double result_x;
	while (abs(a - b) > E) {
		current_x = (a - b) / 2;
		result_x = polynomial(current_x);
		if (abs(result_x) < E) {
			return current_x;
		}
		if (result_a * result_x < 0) {
			b = current_x;
		}
		a = current_x;
	}
	return current_x;
}

double newtonMetod(double a, double b) {

	if (func(a) * func(b) > 0) {
		cout << "Function doesn't meet essential assumptions ";
		return 1;
	}


}
int main(int argc, char* argv[]) {
	double x = 14.4;
	cout << samplePolynomial(x) << endl;
	cin.get();
}