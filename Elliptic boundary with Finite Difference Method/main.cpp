//main.cpp

#include <vector>
#include "structs.h"
#include "input.h"
#include "grid_maker.h"

int main()
{
   int subdomainCount = 0;
   std::vector<Subdomain> subdomains;
   Grid grid;
   std::vector<double> x, y;

   bool correctData = Input(subdomainCount, subdomains, grid);
   if (correctData)
   {
      BuildGrid(grid, subdomains);
      DiagonalMatrix matrix(x.size());
   }

   return 0;
}