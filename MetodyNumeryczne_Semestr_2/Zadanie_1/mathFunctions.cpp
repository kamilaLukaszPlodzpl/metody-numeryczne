#include "mathFunctions.hpp"
#include "mathFunctionsList.cpp"
#include <string>
#include <vector>

namespace mathFunction
{
	double superposition(function f, function g, double x) {
		return f(g(x));
	}

	struct functionMeta {
		function func;
		std::string name;
	};

	void registerFunction(function func, std::string name) {
		functionMeta a = {
			func,
			name
		};
		list.push_back(a);
	}

	void initFunctions()
	{
		registerFunction(mathFunctionList::same, "f(x)=x");
		registerFunction(mathFunctionList::Polynomial_1, "4x^3+2x^2+x-5");
		registerFunction(mathFunctionList::Polynomial_1, "x^2+x-3");
	}
}