#include "mathFunctions.hpp"
#include "mathFunctionsList.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace mathFunction
{
	functionMeta createFunctionMeta(function func, std::string name) {
		functionMeta a = {
			func,
			name
		};
		return a;
	}

	void selectFunction(functionMeta &f)
	{
		std::cout << "                              \n";
		functionMetaArr list = getFunctions();
		size_t size = list.size();
		for (int i = 0; i < size; i++)
			std::cout << " " << i << ". f(x)=" << list[i].name << std::endl;

		int fid = -1;
		while (fid < 0 || fid >= size)
		{
			std::cout << "Wskaz funkcje f(x) ";
			std::cin >> fid;
			std::cout << std::endl;
		}
		f = list[fid];
	}

	functionMetaArr getFunctions() {
		functionMetaArr arr;
		arr.push_back(createFunctionMeta(mathFunctionList::same, "x"));
		arr.push_back(createFunctionMeta(mathFunctionList::f1, "abs(10/x)"));
		arr.push_back(createFunctionMeta(mathFunctionList::f2, "-abs(0.01x)+1"));
		arr.push_back(createFunctionMeta(mathFunctionList::f3, "x^2+3"));
		arr.push_back(createFunctionMeta(mathFunctionList::f4, "exp(-x-x^2)"));
		arr.push_back(createFunctionMeta(mathFunctionList::f5, "|x|"));
		return arr;
	}

}