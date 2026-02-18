//structs.h

#pragma once 

struct Node
{
	double X, Y;
	int GlobalNum;
	Node(double x, double y, int globalNum)
	{
		X = x;
		Y = y;
		GlobalNum = globalNum;
	}
};

struct Subdomain
{
	double Ax, Bx, Ay, By, Hx, Hy;
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
