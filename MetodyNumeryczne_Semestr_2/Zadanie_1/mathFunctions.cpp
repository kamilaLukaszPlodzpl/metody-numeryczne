#include "mathFunctions.hpp"
#include "mathFunctionsList.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace mathFunction
{
	double superposition(function f, function g, double x) {
		return f(g(x));
	}

	functionMeta createFunctionMeta() {
		return createFunctionMeta(mathFunctionList::same, "f(x)=x");
	}

	functionMeta createFunctionMeta(function func, std::string name) {
		functionMeta a = {
			func,
			name
		};
		return a;
	}

	void selectTwoFunctions(functionMeta &f, functionMeta &g) {
		functionMetaArr list = getFunctions();
		size_t size = list.size();
		for (int i = 0; i < size; i++)
			std::cout << " " << i << ". " << list[i].name << std::endl;

		int fid = -1;
		while (fid < 0 || fid >= size)
		{
			std::cout << "Wskaz funkcje f(x) ";
			std::cin >> fid;
			std::cout << std::endl;
		}

		int gid = -1;
		while (gid < 0 || gid >= size)
		{
			std::cout << "Wskaz funkcje g(x) ";
			std::cin >> gid;
			std::cout << std::endl;
		}

		f = list[fid];
		g = list[gid];
	}

	functionMetaArr getFunctions() {
		functionMetaArr arr;
		arr.push_back(createFunctionMeta(mathFunctionList::same, "x"));
		arr.push_back(createFunctionMeta(mathFunctionList::Polynomial_1, "4x^3+2x^2+x-5"));
		arr.push_back(createFunctionMeta(mathFunctionList::Polynomial_1, "x^2+x-3"));
		return arr;
	}
}