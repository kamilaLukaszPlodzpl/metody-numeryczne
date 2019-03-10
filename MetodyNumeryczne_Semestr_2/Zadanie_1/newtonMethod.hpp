#pragma once
#include "mathFunctions.hpp"

double newtonA(mathFunction::function func, mathFunction::function derivative, double a, double b, double epsilon, int &iteration); //metoda stycznych
double newtonB(mathFunction::function func, mathFunction::function derivative, double a, double b, double &epsilon, int iteration);