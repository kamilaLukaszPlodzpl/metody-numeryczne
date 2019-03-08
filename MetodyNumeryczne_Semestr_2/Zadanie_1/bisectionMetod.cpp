#include <iostream>
#include "bisectionMetod.hpp"


double bisection(double a, double b) {
	double E; //ten epsilon ale jeszcze nie wiem czym on jest
	double result_a = polynomial(a); //polynomial = przykladowa funkcja
	double result_b = polynomial(b);
	if ((result_a * result_b) > 0) {
		cout << "Function doesn't meet essential assumptions "; // wartosc funkcji na krancach przedzialu musi miev rozne znaki
		return;
	}
	double current_x;
	double result_x;
	while (abs(a - b) < E) {
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