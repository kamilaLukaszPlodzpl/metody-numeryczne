#pragma once
#include "mathFunctions.hpp"

double bisectionA(mathFunction::function func, double a, double b, double epsilon, int &iteration);// warunek dokladnosci
double bisectionB(mathFunction::function func, double a, double b, double &epsilon, int iteration);// warunek iteracji