#include <iostream>
#include <iomanip>
#include <vector>
#include "mathUtility.hpp"
#include "gnuplot.hpp"
#include "mathFunctions.hpp"
#define	SQRT_PI 1.7724538509

using namespace std;

namespace math
{
	double horner(vector<double> a, double x)
	{
		double out = 0;
		for (int i = 0; i < a.size(); i++)
		{
			out *= x;
			out += a[i];
		}
		return out;
	}
	double hermitePolynominal(unsigned int i, double x)
	{
		vector<double> a;
		switch (i) {
		case 0:
			a = { 1 };
			break;
		case 1:
			a = { 2, 0 };
			break;
		case 2:
			a = { 4, 0, -2 };
			break;
		case 3:
			a = { 8, 0, -12, 0 };
			break;
		case 4:
			a = { 16, 0, -48, 0, 12 };
			break;
		case 5:
			a = { 32, 0, -160, 0, 120, 0 };
			break;
		case 6:
			a = { 64, 0, -480, 0, 720, 0, -120 };
			break;
		case 7:
			a = { 128, 0, -1344, 0, 3360, 0, -1680, 0 };
			break;
		default:
			a = { };
			break;
		}
		return horner(a, x);
	}
	inline int factorial(int n) 
	{
		int fact = 1;
		for (int i = 1; i <= n; i++)
			fact = fact * i;
		return fact;
	}
	inline int power(int x, int y)
	{
		int o = 1;
		for (int i = 0; i < y; i++)
			o *= x;
		return o;
	}

	double aproximationHermite(mathFunction::function f, int approxSteps, int integralNodes, double x)
	{
		double sum = 0;
		for (int k = 0; k <= approxSteps; k++)
		{
			double a = 1;// = aproximationHermiteFactor(f, approxSteps, k);
			a = 1 / (SQRT_PI * power(2,approxSteps) * factorial(approxSteps));
			a *= integralGaussaHermite(f, integralNodes, k);

			double h = hermitePolynominal(k, x);
			sum += a * h;
		}
		return sum;
	}
	//double aproximationHermiteFactor(mathFunction::function f, int n, int k)
	//{
		//*
		//double result = 1 / (SQRT_PI * pow(2.0, n) * factorial(n));
		//result *= integralGaussaHermite(f, k);
		//return result;
		//*/
	//}

	double integralGaussaHermite(mathFunction::function f, int nodesNumber,int approxStep)
	{
		double integral = 0;
		vector<Node> nodes = hermiteZeroPlaces(nodesNumber);
		for (int i = 0; i < nodes.size(); i++)
		{
			if (nodes[i].weight != 0)
			{
				double weight = nodes[i].weight;
				double fx = f(nodes[i].value)*hermitePolynominal(approxStep,nodes[i].value);
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

}