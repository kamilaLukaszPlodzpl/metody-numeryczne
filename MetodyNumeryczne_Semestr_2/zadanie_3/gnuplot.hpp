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
		bool renderToFile
	);

	void generateScript(
		const char *fileName,
		const double &resolution,
		mathFunction::functionMeta metaF,
		const double &a,
		const double &b,
		bool renderToFile,
		double x1,
		const char *x1L,
		double x2,
		const char *x2L
	);
}