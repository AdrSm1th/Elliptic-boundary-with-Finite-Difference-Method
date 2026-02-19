//matrix_maker.cpp

#include "matrix_maker.h"

//inline double GetLambda(double x, double y, std::vector<Subdomain> &subdomains)
//{
//	for (const auto &subdomain : subdomains)
//	{
//		if(((x > ) && () ) && (() && ()))
//	}
//}

void MakeMatrix(DiagonalMatrix &matrix, std::vector<double> &x, std::vector<double> &y)
{
	int sizeY = y.size();
	int sizeX = x.size();

	//Traversal of non-boundary nodes
	for (int i = 1; i < sizeY - 1; i++)
	{
		for (int j = 1; j < sizeX - 1; j++)
		{
			double hprev = x[j] - x[j - 1];
			double h = x[j + 1] - x[j];
			if (abs(hprev - h) <= DBL_EPSILON * h)
			{
				//double elem = ;
			}
		}
	}
}