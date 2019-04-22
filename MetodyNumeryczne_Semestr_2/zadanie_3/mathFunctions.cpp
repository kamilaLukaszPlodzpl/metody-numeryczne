#include "mathFunctions.hpp"
#include "mathFunctionsList.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace mathFunction
{
	//double superposition(function f, function g, double x) {
	//	return f(g(x));
	//}

	functionMeta createFunctionMeta(function func, std::string name) {
		functionMeta a = {
			func,
			name
		};
		return a;
	}

	void selectFunction(functionMeta &f)
	{
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
		arr.push_back(createFunctionMeta(mathFunctionList::Polynomial_1,"4x^3+2x^2+x-5"));
		arr.push_back(createFunctionMeta(mathFunctionList::Polynomial_2,"x^2+x-3"));
		arr.push_back(createFunctionMeta(mathFunctionList::Trygonometric_1, "4sin(2x)"));
		arr.push_back(createFunctionMeta(mathFunctionList::Exponetial_1, "e^x-1"));
		arr.push_back(createFunctionMeta(mathFunctionList::Polynomial_3, "x^3+2x^2-2x+1"));
		arr.push_back(createFunctionMeta(mathFunctionList::aaa, "sin(x)-3^x"));
		arr.push_back(createFunctionMeta(mathFunctionList::bbb, "cos(log(x))*(sin(x))^2"));
		arr.push_back(createFunctionMeta(mathFunctionList::ccc, "2cos(x)"));
		return arr;
	}
}