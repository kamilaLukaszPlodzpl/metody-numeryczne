#include <iostream>
#include "mathFunctions.hpp"
#include "bisectionMetod.hpp"
#include "newtonMethod.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	// Wybranie 2 funkcji
	mathFunction::functionMeta f, g;
	mathFunction::selectTwoFunctions(f, g);
	/*
	// Z³o¿enie i obliczenie wartoœci 
	cout << "x0 = " << x << endl;
	cout << "f(x)=" << f.name << endl;
	cout << "g(x)=" << g.name << endl;
	cout << "f(x0)=" << f.func(x) << endl;
	cout << "g(x0)=" << g.func(x) << endl;
	cout << "f(g(x0))=" << mathFunction::superposition(f.func, g.func, x) << endl;
	*/
	double intervalStart;
	double intervalEnd;
	int bisectionIteration = 0;
	int newtonIteration = 0;
	cout << "Start point for search interval:";
	cin >> intervalStart;
	cout << "End point for search interval:";
	cin >> intervalEnd;
	double firstX;
	cin >> firstX; //need for newton method
	double bisectionX = bisection(f.func, intervalStart, intervalEnd, bisectionIteration );
	double newtonX = newtonMetod(f.func, intervalStart, intervalEnd, firstX, newtonIteration );
	cout << "Bisection method =" << bisectionX << "Iteration = " << bisectionIteration << '\n';
	cout << "Newton metod =" << newtonX << "Iteration = " << newtonIteration << '\n';
	cin.get();
	cin.get();
	cin.get();
}