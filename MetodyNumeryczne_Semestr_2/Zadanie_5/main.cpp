#include <iostream>
#include <vector>
#include "mathFunctions.hpp"
#include "mathUtility.hpp"
//Jak ta linia nizej zakomentowana to program sie pyta o dane
//W przeciwnym wypadku przyjmuje wartosci domyslne zawarte w kodzie
//#define INPUT_DISABLED 
using namespace std;

int main() {
	mathFunction::functionMeta f;
	double a, b;
//Te hashtagi to s� dyrektywy preprocesora
//Takie co� co si� dzieje przed kompilacj�
#ifdef INPUT_DISABLED 
	f = mathFunction::getFunctions()[3];
	a = -10; b = 10;
#else
	mathFunction::selectFunction(f);
	cout << "Podaj przedzial aproksymacji:\n";
	cin >> a >> b;
#endif
	//*/
	cin.get();
	cin.get();
}