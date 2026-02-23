//structs.h

#pragma once 

struct Subdomain
{
	double Ax, Bx, Ay, By, Nx, Ny, Qx, Qy;
	bool UniformX, UniformY;
	void Init(double ax, double bx, double ay, double by, double nx, double ny, bool uniformX, bool uniformY, double qX, double qY)
	{
		Ax = ax;
		Bx = bx;
		Ay = ay;
		By = by;
		Nx = nx;
		Ny = ny;
		UniformX = uniformX;
		UniformY = uniformY;
		Qx = qX;
		Qy = qY;
	}
};

struct DiagonalMatrix
{
	int Size = 0, DiagonalsCount = 5;
	std::vector<double> Data;
	std::vector<int> Offsets;

	DiagonalMatrix(int size, int Nx)
	{
		Size = size;
		Data.resize(size * DiagonalsCount);
		Offsets.resize(DiagonalsCount);
		Offsets[0] = -Nx;
		Offsets[1] = -1;
		Offsets[2] = 0;
		Offsets[3] = 1;
		Offsets[4] = Nx;
	}
};

struct Grid
{
	std::vector<double> X;
	std::vector<double> Y;
	double Lambda = 0, Gamma = 0;
};