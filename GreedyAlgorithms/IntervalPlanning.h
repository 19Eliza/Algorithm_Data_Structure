#pragma once

#include<iostream>
#include<algorithm>
#include<vector>

namespace IntervalPlanning{

    struct Request{
        double si;
        double fi;
    };

    bool cmp(Request& r1,Request& r2);

    std::vector<Request> GreedyAlgorithm(std::vector<Request>& R);

    void ShowRequest(std::vector<Request> R);
}