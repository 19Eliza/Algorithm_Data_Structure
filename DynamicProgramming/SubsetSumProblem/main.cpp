#include "SubsetSum.h"
#include <iostream>

int main() {

  std::vector<int> w{42,52,38,67,10};
  int W = 47;
  std::cout << dynamicProgramming::SubsetSumProblem(w, W)<<std::endl;
  return 0;
}

