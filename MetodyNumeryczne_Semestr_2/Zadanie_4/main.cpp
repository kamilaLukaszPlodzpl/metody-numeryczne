#include <iostream>
#include "mathFunctions.hpp"
#include "mathUtility.hpp"
using namespace std;


int main(int argc, char* argv[])
{
	mathFunction::functionMeta func;
	mathFunction::selectFunction(func);

	cout << "Funkcja: f(x)=" << func.name << "\n";
	//
	int hermiteNodes = -1;
	while (hermiteNodes < 2 || hermiteNodes > 5)
	{
		cout << "Podaj ilosc(miedzy 2 a 5) wezlow hermita:\n";
		cin >> hermiteNodes;
	}
	double gausssHermiteIntegral = math::integralGaussaHermite(func.func, hermiteNodes);
	cout << "Calka policzona przez kwadrature Gaussa-Hermita: " << gausssHermiteIntegral << "\n";
	//
	double step = 0.01, epsilon = 0.0001;
	while (step <= 0)
	{
		cout << "Podaj dlugosc kroku dla metody Newtona-Cotesa:\n";
		cin >> step;
	}
	while (epsilon <= 0)
	{
		cout << "Podaj dokladnosc dla metody Newtona-Cotesa:\n";
		cin >> epsilon;
	}
	double b = 10000;
	double newtonaCotesaIntegral = math::integralNewtonCotesInfinite(func.func, step, epsilon);
	cout << "Calka policzona przez kwadrature Newtona-Cotesa: " << newtonaCotesaIntegral << "\n";


	cin.get();
	cin.get();
}