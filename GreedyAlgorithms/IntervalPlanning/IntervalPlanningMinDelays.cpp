#include"IntervalPlanningMinDelays.h"


namespace IntervalPlanningMinDelays{

    bool cmp(Request& r1,Request& r2){
        return r1.di<r2.di;
    }

    std::vector<IntervalPlanning::Request> GreedyAlgorithm(std::vector<Request>& R,double s){
        std::vector<IntervalPlanning::Request> A;//A-optimal solution
        
        if(R.empty()) return A;

        sort(R.begin(),R.end(),cmp);

        double f=s;// f-the end time of the last scheduled task

        double si,fi;

        for(auto r:R){
            si=f;
            fi=f+r.ti;
            f=f+r.ti;
            A.push_back(IntervalPlanning::Request{si,fi});
        }
        return A;
    };
}