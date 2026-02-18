//main.cpp

#include <vector>
#include "structs.h"
#include "input.h"
#include "grid_maker.h"

int main()
{
   int subdomainCount = 0;
   std::vector<Subdomain> subdomains;
   std::vector<double> x, y;

   bool correctData = Input(subdomainCount, subdomains);
   if (correctData)
   {
      BuildGrid(x, y, subdomains);
      DiagonalMatrix matrix(x.size());
   }

   return 0;
}