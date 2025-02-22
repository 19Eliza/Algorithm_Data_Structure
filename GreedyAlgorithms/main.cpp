#include"IntervalPlanning.h"

int main(){
    IntervalPlanning::Request req1{3,5};
    IntervalPlanning::Request req2{2,4};
    IntervalPlanning::Request req3{5,8};

    std::vector<IntervalPlanning::Request> R;

    R.push_back(req1);
    R.push_back(req2);
    R.push_back(req3);

    auto A=IntervalPlanning::GreedyAlgorithm(R);
    IntervalPlanning::ShowRequest(A);
}