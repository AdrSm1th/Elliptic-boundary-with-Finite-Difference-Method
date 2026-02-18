//main.cpp

#include <vector>
#include "structs.h"
#include "input.h"
#include "grid_maker.h"

int main()
{
   int subdomainCount = 0;
   std::vector<Subdomain> subdomains;
   bool correct = true;
   std::vector<double> x, y;

   Input(subdomainCount, subdomains, correct);
   BuildGrid(x, y, subdomains);

   return 0;
}