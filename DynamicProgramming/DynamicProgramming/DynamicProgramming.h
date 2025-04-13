#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

namespace dynamicProgramming {
int SubsetSumProblem(const std::vector<int> &w, const int &W);

int KnapsackProblem(const std::vector<int> &w, const std::vector<int> &c,
                    const int &W);

std::pair<int,std::set<int>> KnapsackProblemWithObjects(const std::vector<int> &w,const std::vector<int> &c, const int &W);

} // namespace dynamicProgramming