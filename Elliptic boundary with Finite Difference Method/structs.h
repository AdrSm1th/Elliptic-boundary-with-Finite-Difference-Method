//structs.h

#pragma once 

struct Subdomain
{
	double Ax, Bx, Ay, By, Hx, Hy, Lambda;
	bool UniformX, UniformY;
	void Init(double ax, double bx, double ay, double by, double hx, double hy, bool uniformX, bool uniformY)
	{
		Ax = ax;
		Bx = bx;
		Ay = ay;
		By = by;
		Hx = hx;
		Hy = hy;
		UniformX = uniformX;
		UniformY = uniformY;
	}
};

struct DiagonalMatrix
{
	int Size = 0, DiagonalsCount = 5;
	std::vector<double> Data;
	std::vector<int> Offsets;

	DiagonalMatrix(int size)
	{
		Size = size;
		Data.resize(size * DiagonalsCount);
		Offsets.resize(DiagonalsCount);
		Offsets[0] = -size;
		Offsets[1] = -1;
		Offsets[2] = 0;
		Offsets[3] = 1;
		Offsets[4] = size;
	}
};

struct Grid
{
	std::vector<double> X;
	std::vector<double> Y;
	double Lambda, Gamma;
};