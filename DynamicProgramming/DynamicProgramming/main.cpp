#include "DynamicProgramming.h"
#include <iostream>

int main() {

  std::vector<int> w{42,52,38,67,10};
  int W = 47;
  std::cout << dynamicProgramming::SubsetSumProblem(w, W)<<std::endl;

  std::vector<dynamicProgramming::Request> r{{1,4,1},{2,6,3},{1,5,7}};
  std::cout<<dynamicProgramming::WeightedIntervalScheduling(r)<<std::endl;
  return 0;
}
