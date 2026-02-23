//main.cpp

#include <vector>
#include "structs.h"
#include "input.h"
#include "grid_maker.h"
#include "matrix_maker.h"
#include "SLE_solver.h"
#include "output.h"

int main()
{
   int subdomainCount = 0;
   std::vector<Subdomain> subdomains;
   std::vector<double> b, q;
   Grid grid;

   bool correctData = Input(subdomainCount, subdomains, grid);
   if (correctData)
   {
      BuildGrid(grid, subdomains);
      int mSize = grid.X.size() * grid.Y.size();
      DiagonalMatrix matrix(mSize, grid.X.size());
      b.resize(mSize);
      q.resize(mSize);
      BuildMatrix(matrix, grid, b);
      SolveWithGaussZeidel(0.5, 1e-16, matrix, b, q, 10000);
      Output(q, grid);
   }

   return 0;
}