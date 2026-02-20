//main.cpp

#include <vector>
#include "structs.h"
#include "input.h"
#include "grid_maker.h"
#include "matrix_maker.h"

int main()
{
   int subdomainCount = 0;
   std::vector<Subdomain> subdomains;
   std::vector<double> f;
   Grid grid;

   bool correctData = Input(subdomainCount, subdomains, grid);
   if (correctData)
   {
      BuildGrid(grid, subdomains);
      int mSize = grid.X.size() * grid.Y.size();
      DiagonalMatrix matrix(mSize);
      f.resize(mSize);
      BuildMatrix(matrix, grid, f);
   }

   return 0;
}