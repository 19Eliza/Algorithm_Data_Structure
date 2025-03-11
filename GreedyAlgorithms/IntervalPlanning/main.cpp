#include "IntervalPlanningMinDelays.h"

int main() {
  IntervalPlanning::Request req1{3, 5};
  IntervalPlanning::Request req2{2, 4};
  IntervalPlanning::Request req3{5, 8};

  std::vector<IntervalPlanning::Request> R;

  R.push_back(req1);
  R.push_back(req2);
  R.push_back(req3);

  auto A = IntervalPlanning::GreedyAlgorithm(R);
  IntervalPlanning::ShowRequest(A);

  IntervalPlanningMinDelays::Request r1{2, 1};
  IntervalPlanningMinDelays::Request r2{4, 2};
  IntervalPlanningMinDelays::Request r3{6, 3};

  std::vector<IntervalPlanningMinDelays::Request> R_;

  R_.push_back(r1);
  R_.push_back(r2);
  R_.push_back(r3);

  double s = 0;
  auto A_ = IntervalPlanningMinDelays::GreedyAlgorithm(R_, s);
  IntervalPlanning::ShowRequest(A_);
}