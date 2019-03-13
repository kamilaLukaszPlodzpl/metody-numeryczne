#pragma once
#include "mathFunctions.hpp"

namespace gnuplot
{

	struct point
	{
		double x, y;
	};

	void generateScript(
		const char *fileName,
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b,
		bool renderToFile = false
	);

	void displayFunction(
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b,
		bool saveToFile = false
	);


}