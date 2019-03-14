#include <iostream>
#include <iomanip>
#include "mathFunctions.hpp"
#include "bisectionMetod.hpp"
#include "newtonMethod.hpp"
#include "gnuplot.hpp"
#include <fstream>

using namespace std;

void makeRaport(const char *raportFileName, mathFunction::functionMeta f, double a, double b,const char *method,
	double bisectionX, double bisectionIteration, double bisectionEpsilon,
	double newtonX, double newtonIteration, double newtonEpsilon)
{
	fstream raport(raportFileName, ios::out);
	raport << "Function: f(x)=" << f.name << "\n";
	raport << "range - ( " << a << ", " << b << " )\n";
	raport << method << "\n";
	raport << "Bisection: \n";
	raport << "\t x=" << bisectionX << "\n";
	raport << "\t epsilon=" << bisectionEpsilon << "\n";
	raport << "\t iteration=" << bisectionIteration << "\n";
	raport << "Newton: \n";
	raport << "\t x=" << newtonX << "\n";
	raport << "\t epsilon=" << newtonEpsilon << "\n";
	raport << "\t iteration=" << newtonIteration << "\n";
	raport.close();
}

void algorithmAccurancy(mathFunction::functionMeta f,const double &intervalStart, const double &intervalEnd) {
	double epsilon;
	cout << "Epsilon = ";
	cin >> epsilon;

	int bisectionIteration = 0;
	int newtonIteration = 0;
	double bisectionX = bisectionA(f.func, intervalStart, intervalEnd, epsilon, bisectionIteration);
	double newtonX = newtonA(f.func, f.derivativeFunc, intervalStart, intervalEnd, epsilon, newtonIteration);

	cout << "Bisection method =" << bisectionX << "    Iteration = " << bisectionIteration << '\n';
	cout << "Newton metod =" << newtonX << "     Iteration = " << newtonIteration << '\n';

	gnuplot::displayFunction(0.001, f, intervalStart, intervalEnd, true, bisectionX, "bisectionX", newtonX, "newtonX");
	string raportName = f.name;
	raportName += ".txt";
	makeRaport(raportName.c_str(), f, intervalStart, intervalEnd, "Accurancy", bisectionX, bisectionIteration, epsilon, newtonX, newtonIteration, epsilon);
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

	gnuplot::displayFunction(0.001, f, intervalStart, intervalEnd, true, bisectionX, "bisectionX", newtonX, "newtonX");
	string raportName = f.name;
	raportName += ".txt";
	makeRaport(raportName.c_str(), f, intervalStart, intervalEnd, "Accurancy", bisectionX, iteration, bisectionEpsilon, newtonX, iteration, newtonEpsilon);

}

int main(int argc, char* argv[]) {
	// Select functions to calculate
	mathFunction::functionMeta f;
	mathFunction::selectFunction(f);

	gnuplot::displayFunction(0.01, f, -10, 10, false);

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