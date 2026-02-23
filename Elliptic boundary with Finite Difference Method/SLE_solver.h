//SLE_solver.h

#pragma once

#include <vector>
#include "structs.h"

void SolveWithGaussZeidel(double w, double eps, DiagonalMatrix &a, std::vector<double> &f, std::vector<double> &x, int maxiter);