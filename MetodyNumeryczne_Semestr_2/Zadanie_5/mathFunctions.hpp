#pragma once
#include <string>
#include <vector>
namespace mathFunction
{
	typedef double(*function)(double);

	struct functionMeta {
		function func;
		std::string name;
	};

	typedef std::vector<functionMeta> functionMetaArr;

	functionMeta createFunctionMeta(function func, std::string name);

	void selectFunction(functionMeta &f);

	functionMetaArr getFunctions();

}