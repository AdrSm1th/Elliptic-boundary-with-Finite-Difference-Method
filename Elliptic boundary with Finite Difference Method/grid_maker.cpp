//grid_maker.cpp

#include <set>
#include "grid_maker.h"

//Fills the x and y arrays
void BuildGrid(Grid &grid, std::vector<Subdomain> &subdomains)
{
	std::set<double> tX, tY;
	for (const auto &subdomain : subdomains)
	{
		double ax = subdomain.Ax, bx = subdomain.Bx, nx = subdomain.Nx;
		double ay = subdomain.Ay, by = subdomain.By, ny = subdomain.Ny;

		if (subdomain.UniformX)
		{
			double hx = ((bx - ax) / (nx - 1));
			double currentX = ax;
			tX.insert(currentX);
			for (int j = 1; j < nx; j++)
			{
				currentX += hx;
				tX.insert(currentX);
			}
		}
		else
		{
			double s = ax;
			double q = subdomain.Qx;
			tX.insert(s);
			for (int i = 1; i < nx - 1; i++)
			{
				s *= q;
				tX.insert(s);
			}
			tX.insert(bx);
		}

		if (subdomain.UniformY)
		{
			double hy = ((by - ay) / (ny - 1));
			double currentY = ay;
			tY.insert(currentY);
			for (int j = 1; j < ny; j++)
			{
				currentY += hy;
				tY.insert(currentY);
			}
		}
		else
		{
			double s = ay;
			double q = subdomain.Qy;
			tY.insert(s);
			for (int i = 1; i < ny - 1; i++)
			{
				s *= q;
				tY.insert(s);
			}
			tY.insert(by);
		}
	}

	grid.X.assign(tX.begin(), tX.end());
	grid.Y.assign(tY.begin(), tY.end());
}