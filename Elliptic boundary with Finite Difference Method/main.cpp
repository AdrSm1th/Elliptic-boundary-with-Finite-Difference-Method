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
   Grid grid;

   bool correctData = Input(subdomainCount, subdomains, grid);
   if (correctData)
   {
      BuildGrid(grid, subdomains);
      DiagonalMatrix matrix(grid.X.size());
      BuildMatrix(matrix, grid);
   }

   return 0;
}