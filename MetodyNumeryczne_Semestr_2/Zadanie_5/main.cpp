#include <iostream>
#include <fstream>
#include <vector>
#include "mathFunctions.hpp"
#include "mathUtility.hpp"
#include "gnuplot.hpp"
//Jak ta linia nizej zakomentowana to program sie pyta o dane
//W przeciwnym wypadku przyjmuje wartosci domyslne zawarte w kodzie
#define INPUT_DISABLED 
using namespace std;

int main() {
	mathFunction::functionMeta f;
	double a, b;
	int nodes;
//Te hashtagi to s¹ dyrektywy preprocesora
//Takie coœ co siê dzieje przed kompilacj¹
#ifdef INPUT_DISABLED 
	f = mathFunction::getFunctions()[5];
	b = 1;
	a = -b;
	nodes = 5;
	cout << "Funkcja: " << f.name << "\n";
	cout << "Przedzial aproksymacji: ( " << a << " ; " << b << " )\n";
	cout << "Ilosc wezlow: " << nodes << "\n";
#else
	mathFunction::selectFunction(f);
	cout << "Podaj przedzial aproksymacji:\n";
	cin >> a >> b;
	cout << "Podaj ilosc wezlow\n";
	cin >> nodes;
#endif

	vector<gnuplot::point> points;
	for (double i = a; i < b; i+=0.01)
	{
		gnuplot::point p;
		p.x = i;
		p.y = f.func(p.x);
		points.push_back(p);
	}
	vector<gnuplot::point> approximatedPoints;
	for (double i = a; i < b; i += 0.01)
	{
		gnuplot::point p;
		p.x = i;
		p.y = math::aproximationHermite(f.func, nodes, p.x);
		approximatedPoints.push_back(p);
	}

	gnuplot::script* script = gnuplot::initializeScript();
	gnuplot::plot(script, points, "real", true);
	gnuplot::plot(script, approximatedPoints, "approximated", true);
	ofstream file("script.plt");
	gnuplot::save(script, file);
	file.close();
	//*/
	cin.get();
	cin.get();
}