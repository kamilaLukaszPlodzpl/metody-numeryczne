#include "mathFunctions.hpp"
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
}