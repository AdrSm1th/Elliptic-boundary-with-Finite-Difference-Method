//grid_maker.cpp

#include <set>
#include "grid_maker.h"

//Fills the x and y arrays
void BuildGrid(std::vector<double> &x, std::vector<double> &y, std::vector<Subdomain> &subdomains)
{
	std::set<double> tX, tY;
	for (const auto &subdomain : subdomains)
	{
		double ax = subdomain.Ax, bx = subdomain.Bx, hx = subdomain.Hx;
		double ay = subdomain.Ay, by = subdomain.By, hy = subdomain.Hy;

		if (subdomain.UniformX)
		{
			int xCount = static_cast<int>((bx - ax) / hx) + 1;
			double currentX = ax;
			for (int j = 1; j < xCount; j++)
			{
				currentX += hx;
				tX.insert(currentX);
			}
		}
		else
		{
			double s = ax;
			tX.insert(s);
			while (abs(bx - s) > DBL_EPSILON * hx)
			{
				s *= hx;
				tX.insert(s);
			}
		}

		if (subdomain.UniformY)
		{
			int yCount = static_cast<int>((by - ay) / hy) + 1;
			double currentY = ay;
			for (int j = 1; j < yCount; j++)
			{
				currentY += hy;
				tY.insert(currentY);
			}
		}
		else
		{
			double s = ay;
			tY.insert(s);
			while (abs(by - s) > DBL_EPSILON * hy)
			{
				s *= hy;
				tY.insert(s);
			}
		}
	}

	x.assign(tX.begin(), tX.end());
	y.assign(tY.begin(), tY.end());
}