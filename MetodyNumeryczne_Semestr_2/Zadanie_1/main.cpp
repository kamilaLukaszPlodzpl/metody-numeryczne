#include <iostream>
#include "mathFunctions.hpp"
#include "bisectionMetod.hpp"
#include "newtonMethod.hpp"

using namespace std;


int main(int argc, char* argv[]) {
	double x = 3;
	mathFunction::functionMeta f, g;
	mathFunction::selectTwoFunctions(f, g);
	cout << "x0 = " << x << endl;
	cout << "f(x)=" << f.name << endl;
	cout << "g(x)=" << g.name << endl;
	cout << "f(x0)=" << f.func(x) << endl;
	cout << "g(x0)=" << g.func(x) << endl;
	cout << "f(g(x0))=" << mathFunction::superposition(f.func, g.func, x) << endl;
	cin.get();
	cin.get();
	cin.get();
}