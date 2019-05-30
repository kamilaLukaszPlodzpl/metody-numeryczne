#include <iostream>
#include "mathFunctions.hpp"
#include "mathUtility.hpp"
using namespace std;


int main(int argc, char* argv[])
{
	mathFunction::functionMeta func;
	mathFunction::selectFunction(func);

	cout << "Funkcja: f(x)=" << func.name << "\n";
	cout << "Liczenie calki z g(x)=exp(-x^2)*f(x)\n";
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
	double epsilon = -0.0000001;
	while (epsilon <= 0)
	{
		cout << "Podaj dokladnosc dla metody Newtona-Cotesa:\n";
		cin >> epsilon;
	}

	int iterationsNewtonCotesIntegral = 0;
	double newtonCotesIntegral = math::integralNewtonCotes(func.func, epsilon, -1000, 1000, iterationsNewtonCotesIntegral);
	cout << "Calka policzona przez kwadrature na przedziale < -1000 , 1000 > Newtona-Cotesa: " << newtonCotesIntegral << "  Iteracje: "<< iterationsNewtonCotesIntegral <<  "\n";
	int iterationsNewtonCotesIntegralInfinity = 0;
	double a = 0, b = 0;
	double newtonCotesIntegralInfinity = math::integralNewtonCotesInfinite(func.func, epsilon, a, b, iterationsNewtonCotesIntegralInfinity);
	cout << "Proba przyblizenia calki dla przedzialu nieskonczonego.\n";
	cout << "Calka policzona przez kwadrature na przedziale <" << a << " , " << b << "> Newtona-Cotesa: " << newtonCotesIntegralInfinity << "  Iteracje: " << iterationsNewtonCotesIntegralInfinity<<"\n";


	cin.get();
	cin.get();
}