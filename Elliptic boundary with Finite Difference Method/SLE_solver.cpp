//SLE_solver.cpp

#include "SLE_solver.h"

inline std::vector<double> VectorMatrixMultiplication(DiagonalMatrix &a, std::vector<double> &x)
{
	size_t n = x.size();
	std::vector<double> res(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a.DiagonalsCount; j++)
		{
			if (i + a.Offsets[j] < 0 || i + a.Offsets[j] >= n) continue;
			res[i] += a.Data[j * n + i] * x[i + a.Offsets[j]];
		}
	}
	return res;
}

inline void VectorDifference(std::vector<double> &vector_1, std::vector<double> &vector_2)
{
	size_t n = vector_1.size();
	for (int i = 0; i < n; i++)
	{
		vector_1[i] -= vector_2[i];
	}
}

inline double VectorNorm(std::vector<double> &vector)
{
	double result = 0;
	for (int i = 0; i < vector.size(); i++)
		result += vector[i] * vector[i];
	return sqrt(result);
}

void SolveWithGaussZeidel(double w, double eps, DiagonalMatrix &a, std::vector<double> &f, std::vector<double> &x, int maxiter)
{
	size_t n = f.size();
	double discrepancy = 0;
	int iter = 0;
	do
	{
		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int j = 0; j < a.DiagonalsCount; j++)
			{
				if (i + a.Offsets[j] < 0 || i + a.Offsets[j] >= n) continue;
				sum += a.Data[j * n + i] * x[i + a.Offsets[j]];
			}
			x[i] += (w / a.Data[2 * n + i]) * (f[i] - sum);
		}
		iter++;
		std::vector<double> Ax = VectorMatrixMultiplication(a, x);
		VectorDifference(Ax, f);
		discrepancy = VectorNorm(Ax) / VectorNorm(f);
	} while (discrepancy > eps && iter < maxiter);
}