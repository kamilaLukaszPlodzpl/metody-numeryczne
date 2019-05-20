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
		double h = abs(a-b)/3.0;
		double simson = ( f(a)*exp(-(a*a)) +f((a+b)/2)*exp(-(((a+b)/2)*((a + b) / 2))) + f(b)*exp(-(b*b)) );
		simson *= h;
		return simson;
	}
	double integralNewtonCotes(mathFunction::function f, double epsilon, double a, double b, int &iterations)
	{
		iterations = 0;
		double step = abs(b-a);
		double integralOld, integralNew = 0;
		do
		{
			iterations++;
			integralOld = integralNew;
			step /= 10.0;
			integralNew = 0;

			for (double x = a; x <= (b - step); x += step)
			{
				double simson = simsonFormula(f, x, x + step);
				integralNew += simson;
			}

		} while (abs(abs(integralNew)-abs(integralOld)) > epsilon );
		return integralNew;
	}
	double integralNewtonCotesInfinite(mathFunction::function f, double epsilon, double &a, double &b, int &iterations)
	{
		double integral = 0;
		bool plus,minus;
		b = limitPlusInf(f, epsilon, plus);
		a = limitMinusInf(f, epsilon, minus);
		int iter = 0;
		integral = integralNewtonCotes(f,epsilon, a, b, iter);
		iterations = iter;
		return integral;
	}

	double integralGaussaHermite(mathFunction::function f,int nodesNumber)
	{
		double integral = 0;
		vector<Node> nodes = hermiteZeroPlaces(nodesNumber);
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i].weight != 0)
			{
				double weight = nodes[i].weight;
				double fx = f(nodes[i].value);
				integral += weight * fx;
			}
		}
		return integral;
	}

	std::vector<Node> hermiteZeroPlaces(int n)
	{
		vector<Node> x;
		math::Node t;
		switch (n)
		{
		case 2:
			t.value = -0.707107; t.weight = 0.886227; x.push_back(t);
			t.value = 0.707107; t.weight = 0.886227; x.push_back(t);
			break;
		case 3:
			t.value = -1.224745; t.weight = 0.295409; x.push_back(t);
			t.value = 0.000000; t.weight = 1.181636; x.push_back(t);
			t.value = 1.224745; t.weight = 0.295409; x.push_back(t);
			break;
		case 4:
			t.value = -1.650680; t.weight = 0.081313; x.push_back(t);
			t.value = -0.534648; t.weight = 0.804914; x.push_back(t);
			t.value = 0.534648; t.weight = 0.804914; x.push_back(t);
			t.value = 1.650680; t.weight = 0.081313; x.push_back(t);
			break;
		case 5:
			t.value = -2.020183; t.weight = 0.019953; x.push_back(t);
			t.value = -0.958572; t.weight = 0.393619; x.push_back(t);
			t.value = 0.000000; t.weight = 0.945309; x.push_back(t);
			t.value = 0.958572; t.weight = 0.393619; x.push_back(t);
			t.value = 2.020183; t.weight = 0.019953; x.push_back(t);
			break;
		}
		return x;
	}

	double limitPlusInf(mathFunction::function f, double epsilon, bool &exist)
	{
		double step = epsilon*100;
		double x = 0;
		double oldY, newY = f(x)*exp(-(x*x));
		do
		{
			oldY = newY;
			x += step;
			newY = f(x)*exp(-(x*x));
		} while (abs(abs(oldY) - abs(newY)) > epsilon);
		return x;
	}

	double limitMinusInf(mathFunction::function f, double epsilon, bool &exist)
	{
			//epsilon = 0.000000000000001;
			double step = epsilon*100;
			double x = 0;
			double oldY, newY = f(x)*exp(-(x*x));
			do
			{
				oldY = newY;
				x -= step;
				newY = f(x)*exp(-(x*x));
			} while (abs(abs(oldY) - abs(newY)) > epsilon);
			return x;
	}



}