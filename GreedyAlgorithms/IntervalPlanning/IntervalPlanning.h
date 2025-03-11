#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

namespace IntervalPlanning {

struct Request {
  double si; // begin of request
  double fi; // end of request
};

bool cmp(Request &r1, Request &r2);

std::vector<Request>
GreedyAlgorithm(std::vector<Request> &R); // R-set of request

void ShowRequest(std::vector<Request> R);
} // namespace IntervalPlanning