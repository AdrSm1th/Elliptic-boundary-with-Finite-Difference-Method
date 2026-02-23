//output.cpp

#include "output.h"

inline double q_an(double x, double y)
{
	return sin(10 * x) * sin(10 * y);
}

void Output(std::vector<double> q, Grid grid)
{
	std::ofstream output("output.txt");

	output << "x" << std::setw(20) << "y" << std::setw(20) << "q" << std::setw(21) << "q*" << std::setw(24) << "q - q*" << std::endl;

	int idx = 0;

	for (int i = 0; i < grid.Y.size(); i++)
	{
		for (int j = 0; j < grid.X.size(); j++)
		{
			double qs = q[idx++];
			double qan = q_an(grid.X[j], grid.Y[i]);
			output << std::setprecision(16) << std::fixed;
			output << grid.X[j] << std::setw(20) << grid.Y[i] << std::setw(20) << qan << std::setw(20) << qs << std::setw(20) << qan - qs << std::endl;;
		}
	}

	output.close();
}

//void OutputAandF(DiagonalMatrix A, std::vector<double> f)
//{
//	std::ofstream A("A.txt");
//	std::ofstream F("f.txt");
//
//	for (int i = 0; i < grid.Y.size(); i++)
//	{
//		for (int j = 0; j < grid.X.size(); j++)
//		{
//			double qs = q[idx++];
//			double qan = q_an(grid.X[j], grid.Y[i]);
//			output << std::setprecision(16) << std::fixed;
//			output << grid.X[j] << std::setw(20) << grid.Y[i] << std::setw(20) << qan << std::setw(20) << qs << std::setw(20) << qan - qs << std::endl;;
//		}
//	}
//}