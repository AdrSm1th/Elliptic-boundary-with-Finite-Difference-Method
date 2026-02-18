//main.cpp

#include <vector>
#include "structs.h"
#include "input.h"

int main()
{
   int subdomainCount = 0;
   std::vector<Subdomain> subdomains;
   bool correct = true;

   Input(subdomainCount, subdomains, correct);

   return 0;
}