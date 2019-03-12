#include <iostream>
#include <iomanip>
#include "mathFunctions.hpp"
#include "bisectionMetod.hpp"
#include "newtonMethod.hpp"
#include "gnuplot.hpp"



using namespace std;

void algorithmAccurancy(mathFunction::functionMeta f,const double &intervalStart, const double &intervalEnd) {
	double epsilon;
	cout << "Epsilon = ";
	cin >> epsilon;

	int bisectionIteration = 0;
	int newtonIteration = 0;
	double bisectionX = bisectionA(f.func, intervalStart, intervalEnd, epsilon, bisectionIteration);
	double newtonX = newtonA(f.func, f.derivativeFunc, intervalStart, intervalEnd, epsilon, newtonIteration);

	cout << "Bisection method =" << scientific << bisectionX << "    Iteration = " << bisectionIteration << '\n';
	cout << "Newton metod =" << scientific << newtonX << "     Iteration = " << newtonIteration << '\n';
}

void algorithIteration(mathFunction::functionMeta f, const double &intervalStart, const double &intervalEnd) {

	int iteration;
	cout << "Iteration =";
	cin >> iteration;

	double newtonEpsilon = 0;
	double bisectionEpsilon = 0;
	double bisectionX = bisectionB(f.func, intervalStart, intervalEnd, bisectionEpsilon, iteration);
	double newtonX = newtonB(f.func, f.derivativeFunc, intervalStart, intervalEnd, newtonEpsilon, iteration);

	cout << "Bisection method =" << setprecision(50) << bisectionX << " Acurrancy = " << setprecision(50) << bisectionEpsilon << '\n';
	cout << "Newton metod =" << scientific << newtonX << "Acurrancy = " << scientific << newtonEpsilon << '\n'; // wyswietlanie poprawic 
}

int main(int argc, char* argv[]) {
	// Select functions to calculate
	mathFunction::functionMeta f;
	mathFunction::selectFunction(f);

	//
	char algorithm = '0';
	while (algorithm != 'a' && algorithm != 'b') {
		cout << "Select type of algorithm:" << '\n' << "a: accurancy" << '\n' << "b: iteration" << '\n';
		cin >> algorithm;
	}

	double intervalStart, intervalEnd;
	cout << "Start point for search interval:";
	cin >> intervalStart;
	cout << "End point for search interval:";
	cin >> intervalEnd;

	// Calculate
	if (algorithm == 'a') {
		algorithmAccurancy(f, intervalStart, intervalEnd);
	}
	else {
		algorithIteration(f, intervalStart, intervalEnd);
	}

	cin.get();
	cin.get();
}