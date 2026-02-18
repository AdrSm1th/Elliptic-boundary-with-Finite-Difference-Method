//input.cpp

#include <fstream>
#include <cmath>
#include <iostream>
#include "input.h"

inline bool Check(double a, double b, double h, bool uniform)
{
	//For a uniform grid hx and hy are the step. For a non uniform grid hx and hy are q
	if (uniform)
	{
		return (abs(std::fmod(b - a, h)) <= DBL_EPSILON * std::abs(h)); //The number of steps must be an integer
	}
	else
	{
		//geometric progression
		if (h <= 1) return false;
		double s = a;
		while (s < b)
		{
			s *= h;
			if (std::abs(b - s) <= DBL_EPSILON * h) return true;
		}
		return false;
	}
}

bool Input(int &subdomainCount, std::vector<Subdomain> &subdomains)
{
	std::ifstream input("input.txt");
	input >> subdomainCount;
	subdomains.resize(subdomainCount);
	for (int i = 0; i < subdomainCount; i++)
	{
		double ax, bx, ay, by, hx, hy;
		bool uniformX, uniformY;
		input >> uniformX >> ax >> bx >> hx >> uniformY >> ay >> by >> hy;

		if (Check(ax, bx, hx, uniformX) && Check(ay, by, hy, uniformY)) subdomains[i].Init(ax, bx, ay, by, hx, hy, uniformX, uniformY);
		else
		{
			std::cout << "Incorrect input: subdomain: " << i + 1 << std::endl;
			return false;
		}
	}
	input.close();
	return true;
}