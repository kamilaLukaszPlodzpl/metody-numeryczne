#pragma once
#include "mathFunctions.hpp"

namespace gnuplot
{
	void generateScript(mathFunction::function f, const double &a, const double &b, const double &resolution, const char *fileName);
}