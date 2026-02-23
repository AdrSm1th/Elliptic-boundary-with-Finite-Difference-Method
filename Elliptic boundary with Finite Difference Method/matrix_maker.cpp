//matrix_maker.cpp

#include "matrix_maker.h"

inline double Func(double x, double y)
{
	return sin(10 * x) * sin(10 * y);
}

inline double f(double x, double y)
{
	return 200 * sin(10 * x) * sin(10 * y) + sin(10 * x) * sin(10 * y);
}

void BuildMatrix(DiagonalMatrix &matrix, Grid &grid, std::vector<double> &b)
{
	int sizeX = grid.X.size();
	int sizeY = grid.Y.size();
	int n = matrix.Size;

	//Traversal of non-boundary nodes
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			int globalNum = i * sizeX + j;
			if ((i - 1 < 0) || (i + 1 >= sizeY) || (j - 1 < 0) || (j + 1 >= sizeX))
			{
				matrix.Data[2 * n + globalNum] = 1;
				b[globalNum] = Func(grid.X[j], grid.Y[i]);
				continue;
			}

			//X term
			double hprev = grid.X[j] - grid.X[j - 1];
			double h = grid.X[j + 1] - grid.X[j];
			double c1 = 0, c2 = 0, c3 = 0;
			if (abs(hprev - h) <= DBL_EPSILON * std::max(h, hprev))
			{
				c1 = -grid.Lambda / (h * h);
				c2 = 2 * grid.Lambda / (h * h);
				c3 = c1;
			}
			else
			{
				c1 = -grid.Lambda * 2 / (hprev * (h + hprev));
				c2 = 2 * grid.Lambda / (hprev * h);
				c3 = -grid.Lambda * 2 / (h * (h + hprev));
			}
			matrix.Data[n + globalNum] += c1;
			matrix.Data[2 * n + globalNum] += c2;
			matrix.Data[3 * n + globalNum] += c3;

			//Y term
			hprev = grid.Y[i] - grid.Y[i - 1];
			h = grid.Y[i + 1] - grid.Y[i];
			if (abs(hprev - h) <= DBL_EPSILON * std::max(h, hprev))
			{
				c1 = -grid.Lambda / (h * h);
				c2 = 2 * grid.Lambda / (h * h);
				c3 = c1;
			}
			else
			{
				c1 = -grid.Lambda * 2 / (hprev * (h + hprev));
				c2 = 2 * grid.Lambda / (hprev * h);
				c3 = -grid.Lambda * 2 / (h * (h + hprev));
			}
			matrix.Data[0 * n + globalNum] += c1;
			matrix.Data[2 * n + globalNum] += c2;
			matrix.Data[4 * n + globalNum] += c3;

			matrix.Data[2 * n + globalNum] += grid.Gamma;
			b[globalNum] = f(grid.X[j], grid.Y[i]);
		}
	}
}