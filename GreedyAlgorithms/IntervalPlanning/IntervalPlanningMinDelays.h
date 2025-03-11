#pragma once

#include "IntervalPlanning.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace IntervalPlanningMinDelays {
struct Request {
  double di; // deadline time
  double ti; // duration of the application
};

bool cmp(Request &r1, Request &r2);

std::vector<IntervalPlanning::Request>
GreedyAlgorithm(std::vector<Request> &R,
                double s); // R-set of request, s-begin time for all request

void ShowRequest(std::vector<Request> R);
} // namespace IntervalPlanningMinDelays