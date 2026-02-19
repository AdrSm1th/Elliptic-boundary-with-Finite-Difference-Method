//matrix_maker.cpp

#include "matrix_maker.h"

void BuildMatrix(DiagonalMatrix &matrix, Grid &grid)
{
	int sizeX = grid.X.size();
	int sizeY = grid.Y.size();
	int n = matrix.Size;

	//Traversal of non-boundary nodes
	for (int i = 1; i < sizeY - 1; i++)
	{
		for (int j = 1; j < sizeX - 1; j++)
		{
			int globalNum = i * sizeX + j;

			//X term
			double hprev = grid.X[j] - grid.X[j - 1];
			double h = grid.X[j + 1] - grid.X[j];
			double c1 = 0, c2 = 0, c3 = 0;
			if (abs(hprev - h) <= DBL_EPSILON * std::max(h, hprev))
			{
				c1 = -grid.Lambda / (h * h);
				c2 = 2 * grid.Lambda / (h * h);
				c3 = c2;
			}
			else
			{
				c1 = -grid.Lambda / (hprev * (h + hprev));
				c2 = 2 * grid.Lambda / (hprev * h);
				c3 = -grid.Lambda / (h * (h + hprev));
			}
			matrix.Data[1 * n + globalNum] += c1;
			matrix.Data[2 * n + globalNum] += c2;
			matrix.Data[3 * n + globalNum] += c3;

			//Y term
			hprev = grid.Y[i] - grid.Y[i - 1];
			h = grid.Y[i + 1] - grid.Y[i];
			if (abs(hprev - h) <= DBL_EPSILON * std::max(h, hprev))
			{
				c1 = -grid.Lambda / (h * h);
				c2 = 2 * grid.Lambda / (h * h);
				c3 = c2;
			}
			else
			{
				c1 = -grid.Lambda / (hprev * (h + hprev));
				c2 = 2 * grid.Lambda / (hprev * h);
				c3 = -grid.Lambda / (h * (h + hprev));
			}
			matrix.Data[0 * n + globalNum] += c1;
			matrix.Data[2 * n + globalNum] += c2;
			matrix.Data[4 * n + globalNum] += c3;
		}
	}
}