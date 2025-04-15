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

struct Request {
    double si; // begin of request
    double fi; // end of request
    double weight;// weight of request
  };

double WeightedIntervalScheduling(std::vector<Request> r);

} // namespace dynamicProgramming