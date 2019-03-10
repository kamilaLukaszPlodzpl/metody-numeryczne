#pragma once
#include "mathFunctions.hpp"

double bisectionA(mathFunction::function func, double a, double b, double E, int &iteration);
double bisectionB(mathFunction::function func, double a, double b, double E, int &iteration);