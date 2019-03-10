#include <iostream>
#include "mathFunctions.hpp"
#include "bisectionMetod.hpp"
#include "newtonMethod.hpp"

using namespace std;

/*void algorithmA(double intervalStart, double intervalEnd, double firstX) {
	double epsilon;
	int bisectionIteration = 0;
	int newtonIteration = 0;
	cout << "Epsilon = ";
	cin >> epsilon;
	double bisectionX = bisection(f.func, intervalStart, intervalEnd, epsilon, bisectionIteration);
	double newtonX = newtonMetod(f.func, intervalStart, intervalEnd, firstX, epsilon, newtonIteration);
}
void algorithB() {

}
*/

int main(int argc, char* argv[]) {
	// Select functions to calculate
	mathFunction::functionMeta f;
	mathFunction::selectFunction(f);

	//
	char algorithm;
	cout << "Select type of algorithm:" << '\n' << "a: accurancy" << '\n' << "b: iteration" << '\n';
	cin >> algorithm;
	double intervalStart;
	double intervalEnd;
	cout << "Start point for search interval:";
	cin >> intervalStart;
	cout << "End point for search interval:";
	cin >> intervalEnd;

	// Need for newton method
	double firstX;
	cout << "Starting x =";
	cin >> firstX;

	// Calculate
	if (algorithm == 'a') {// accurancy condition
		
		double epsilon;
		cout << "Epsilon = ";
		cin >> epsilon;

		int bisectionIteration = 0;
		int newtonIteration = 0;
		double bisectionX = bisectionA(f.func, intervalStart, intervalEnd, epsilon, bisectionIteration);
		double newtonX = newtonA(f.func, intervalStart, intervalEnd, firstX, epsilon, newtonIteration);

		cout << "Bisection method =" << scientific << bisectionX << "    "<< "Iteration = " << bisectionIteration << '\n';
		cout << "Newton metod =" << scientific << newtonX <<"     " << "Iteration = " << newtonIteration << '\n';
	}
	else if (algorithm == 'b') {// iteration condition

		int iteration;
		cout << "Iteration =";
		cin >> iteration;

		double newtonEpsilon = 0;
		double bisectionEpsilon = 0;
		double bisectionX = bisectionB(f.func, intervalStart, intervalEnd, bisectionEpsilon, iteration);
		double newtonX = newtonB(f.func, intervalStart, intervalEnd, firstX, newtonEpsilon, iteration);

		cout << "Bisection method =" << scientific << bisectionX << "Acurrancy = " << bisectionEpsilon << '\n';
		cout << "Newton metod =" << scientific << newtonX << "Iteration = " << newtonEpsilon << '\n';
	}



	 // dla funkcji g to samo jeszcze
	cin.get();
	cin.get();
	cin.get();
}