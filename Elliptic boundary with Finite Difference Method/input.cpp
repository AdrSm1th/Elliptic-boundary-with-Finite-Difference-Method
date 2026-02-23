//input.cpp

#include <fstream>
#include <cmath>
#include <iostream>
#include "input.h"

inline double FindQ(double a, double b, double n, int maxiter)
{
	//geometric progression;
	int iter = 0;
	double step = 1, lastB, q = 2;
	bool prevGrow = false;
	while (iter < maxiter)
	{
		lastB = a;
		for (int i = 0; i < n - 1; i++)
		{
			lastB *= q;
		}
		if (lastB - b > DBL_EPSILON * std::max(lastB, b))
		{
			if (!prevGrow) step /= 2;
			prevGrow = true;
			q -= step;
		}
		else if (lastB - b < -DBL_EPSILON * step * 1000)
		{
			if (prevGrow) step /= 2;
			prevGrow = false;
			q += step;
		}
		else
		{
			return q;
		}

		iter++;
	}
	return 0;
}

bool Input(int &subdomainCount, std::vector<Subdomain> &subdomains, Grid &grid)
{
	std::ifstream input("input.txt");
	double lambda, gamma;
	input >> lambda >> gamma >> subdomainCount;
	grid.Lambda = lambda;
	grid.Gamma = gamma;
	subdomains.resize(subdomainCount);
	for (int i = 0; i < subdomainCount; i++)
	{
		double ax, bx, ay, by, nx, ny, qx, qy;
		bool uniformX, uniformY;
		input >> uniformX >> ax >> bx >> nx >> uniformY >> ay >> by >> ny;

		if (uniformX) qx = 1;
		else
		{
			qx = FindQ(ax, bx, nx, 1000);
		}

		if (uniformY) qy = 1;
		else
		{
			qy = FindQ(ay, by, ny, 1000);
		}

		if(qx != 0 && qy != 0) subdomains[i].Init(ax, bx, ay, by, nx, ny, uniformX, uniformY, qx, qy);
		else
		{
			std::cout << "Incorrect input in subdomain " << i << std::endl;
			return false;
		}
	}
	input.close();
	return true;
}