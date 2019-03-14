#include <iostream>
#include <iomanip>
#include "mathFunctions.hpp"
#include "bisectionMetod.hpp"
#include "newtonMethod.hpp"
#include "gnuplot.hpp"
#include <fstream>
#include <cstdlib>

using namespace std;

void makeRaport(ostream &stream, mathFunction::functionMeta f, double a, double b,const char *method,
	double bisectionX, double bisectionIteration, double bisectionEpsilon,
	double newtonX, int newtonIteration, double newtonEpsilon)
{
	stream << "Function: f(x)=" << f.name << "\n";
	stream << "range - ( " << a << ", " << b << " )\n";
	stream << method << "\n";
	stream
		<< "| Method    | " << setw(10) << "X" << " | " << setw(10) << "epsilon" << " | " << setw(10) << "iteration" << " | \n"
		<< "| Bisection | " << setw(10) << bisectionX << " | " << setw(10) << bisectionEpsilon << " | " << setw(10) << bisectionIteration << " |\n"
		<< "| Newton    | " << setw(10) << newtonX << " | " << setw(10) << newtonEpsilon << " | " << setw(10) << newtonIteration << " |\n"
		;
}

void algorithmAccurancy(mathFunction::functionMeta f,const double &intervalStart, const double &intervalEnd,
	double &bisectionX, int &bisectionIteration, double &bisectionEpsilon, double &newtonX, int &newtonIteration, double &newtonEpsilon
) {
	double epsilon;
	cout << "Epsilon = ";
	cin >> epsilon;
	bisectionEpsilon = epsilon;
	newtonEpsilon = epsilon;

	bisectionIteration = 0;
	newtonIteration = 0;
	bisectionX = bisectionA(f.func, intervalStart, intervalEnd, epsilon, bisectionIteration);
	newtonX = newtonA(f.func, f.derivativeFunc, intervalStart, intervalEnd, epsilon, newtonIteration);
}

void algorithIteration(mathFunction::functionMeta f, const double &intervalStart, const double &intervalEnd,
	double &bisectionX, int &bisectionIteration, double &bisectionEpsilon, double &newtonX, int &newtonIteration, double &newtonEpsilon
) {

	int iteration;
	cout << "Iteration =";
	cin >> iteration;
	bisectionIteration = iteration;
	newtonIteration = iteration;

	newtonEpsilon = 0;
	bisectionEpsilon = 0;
	bisectionX = bisectionB(f.func, intervalStart, intervalEnd, bisectionEpsilon, iteration);
	newtonX = newtonB(f.func, f.derivativeFunc, intervalStart, intervalEnd, newtonEpsilon, iteration);

}

int main(int argc, char* argv[]) {
	// Select functions to calculate
	mathFunction::functionMeta f;
	mathFunction::selectFunction(f);

	// Wyœwietlenie czystego wykresu
	gnuplot::generateScript("temp.plt",0.01, f, -10, 10, false);
	system("temp.plt");
	remove("temp.plt");

	//
	char algorithm = '0';
	while (algorithm != 'a' && algorithm != 'b') {
		cout << "Select type of algorithm:" << '\n' << "a: accurancy" << '\n' << "b: iteration" << '\n';
		cin >> algorithm;
	}

	double intervalStart, intervalEnd;
	cout << "Start point for search interval: ";
	cin >> intervalStart;
	cout << "End point for search interval: ";
	cin >> intervalEnd;

	double bisectionX, bisectionEpsilon;
	int bisectionIteration;
	double newtonX, newtonEpsilon;
	int newtonIteration;
	string method = "";
	// Calculate
	if (algorithm == 'a') {
		algorithmAccurancy(f, intervalStart, intervalEnd, bisectionX, bisectionIteration, bisectionEpsilon, newtonX, newtonIteration, newtonEpsilon);
		method = "accurancy";
	}
	else {
		algorithIteration(f, intervalStart, intervalEnd, bisectionX, bisectionIteration, bisectionEpsilon, newtonX, newtonIteration, newtonEpsilon);
		method = "iteration";
	}
	//Wyœwietlenie wyniku na konsole
	makeRaport(cout, f, intervalStart, intervalEnd, method.c_str(), bisectionX, bisectionIteration, bisectionEpsilon, newtonX, newtonIteration, newtonEpsilon);

	//Generowanie nazwy pliku
	string fileName = "";
	fileName += f.name;
	fileName += "_" + method;
	string fileNameRaport = fileName + ".txt";
	string fileNamePlot = fileName + ".plt";

	//Zapisanie wyniku do pliku
	fstream raportFile(fileNameRaport.c_str(), ios::out);
	makeRaport(raportFile, f, intervalStart, intervalEnd, method.c_str(), bisectionX, bisectionIteration, bisectionEpsilon, newtonX, newtonIteration, newtonEpsilon);
	raportFile.close();

	//Wyœwietlenie wykresu
	gnuplot::generateScript("temp.plt", 0.001, f, intervalStart, intervalEnd, false, bisectionX, "bisectionX", newtonX, "newtonX");
	system("temp.plt");
	remove("temp.plt");

	//Zapisanie skryptu wykresu
	gnuplot::generateScript(fileNamePlot.c_str(),0.001, f, intervalStart, intervalEnd, true, bisectionX, "bisectionX", newtonX, "newtonX");
	
	cin.get();
	cin.get();
}