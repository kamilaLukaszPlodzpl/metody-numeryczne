#pragma once
#include "mathFunctions.hpp"

double newtonA(mathFunction::function func, double a, double b, double x, double E, int &iteration); //metoda stycznych
double newtonB(mathFunction::function func, double a, double b, double x, double E, int &iteration);