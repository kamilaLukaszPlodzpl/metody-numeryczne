#include <iostream>
#include <iomanip>
#include <vector>
#include "mathUtility.hpp"
#include "mathFunctions.hpp"

using namespace std;

namespace math
{

	double simsonFormula(mathFunction::function f, double a, double b)
	{
		double h = abs((a-b) / 3.0);
		double simson = (f(a) +f((a + b) / 2.0) + f(b));
		simson *= h;
		//cout << setw(3) << h << "( " << setw(3) << a << " ; " << setw(3) << b << " ) simson: " << simson << "\n";
		return simson;
	}
	double integralNewtonCotes(mathFunction::function f, double step, double a, double b)
	{
		double integral = 0;
		for (double x = a; x <= (b-step); x += step)
		{
			double simson = simsonFormula(f, x, x + step);
			integral += simson;
		}
		return integral;
	}
	double integralNewtonCotesInfinite(mathFunction::function f,double step,double epsilon)
	{
		double integral = 0;
		double partIntegral,x = 0;
		do
		{
			partIntegral = simsonFormula(f, x, x + step);
			integral += partIntegral;
			x += step;
		} while (abs(integral)>epsilon);
		x = 0;
		partIntegral = 0;
		do
		{
			partIntegral = simsonFormula(f, x - step, x);
			integral += partIntegral;
			x -= step;
		} while (abs(partIntegral) > epsilon);
		return integral;
	}

	double integralGaussaHermite(mathFunction::function f,int nodesNumber)
	{
		double integral = 0;
		vector<double> nodes = hermiteZeroPlaces(nodesNumber);
		for (int i = 0; i < nodes.size(); i++)
		{
			double weight = exp(-(nodes[i] * nodes[i]));
			double fx = f(nodes[i]);
			integral += weight * fx;
		}
		return integral;
	}

	std::vector<double> hermiteZeroPlaces(int n)
	{
		vector<double> x;
		switch (n)
		{
		case 2:
			x.push_back(-0.707106781187);
			x.push_back(0.707106781187);
			break;
		case 3:
			x.push_back(-1.22474487139);
			x.push_back(0);
			x.push_back(1.22474487139);
			break;
		case 4:
			x.push_back(-1.65068012389);
			x.push_back(-0.524647623275);
			x.push_back(0.524647623275);
			x.push_back(1.65068012389);
			break;
		case 5:
			x.push_back(-2.02018287046);
			x.push_back(-0.958572464614);
			x.push_back(0);
			x.push_back(0.958572464614);
			x.push_back(2.02018287046);
			break;
		}
		return x;
	}

	double limit(mathFunction::function f, double x, bool &exist)
	{
		double limitPlus = 0;
		for (double h = 10; h > 0; h -= 0.0001)
		{
			double newlimitPlus = (f(x + h) - f(x)) / h;
			if (abs(newlimitPlus - limitPlus) <= 0.0001)
			{
				limitPlus = newlimitPlus;
				break;
			}
			limitPlus = newlimitPlus;
		}

		double limitMinus = 0;
		for (double h = -10; h < 0; h += 0.0001)
		{
			double newlimitMinus = (f(x + h) - f(x)) / h;
			if (abs(newlimitMinus - limitMinus) <= 0.0001)
			{
				limitMinus = newlimitMinus;
				break;
			}
			limitMinus = newlimitMinus;
		}

		double limit = (limitPlus + limitMinus) / 2;;
		exist = ((limitMinus*limitPlus >= 0) && (abs(limitPlus - limitMinus) < 0.001)) ||
			((limitMinus*limitPlus < 0) && (abs(limitPlus + limitMinus) < 0.001));
		return limit;
	}
}