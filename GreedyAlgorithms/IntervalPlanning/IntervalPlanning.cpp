#include"IntervalPlanning.h"

namespace IntervalPlanning{

    bool cmp(Request& r1,Request& r2){
        return r1.fi<r2.fi;
    }

    std::vector<Request> GreedyAlgorithm(std::vector<Request>& R){

        if(R.empty()) return R;

        sort(R.begin(),R.end(),cmp);

        std::vector<Request> A;

        auto r=R.begin();
        A.push_back(*r);
        auto f=r->fi;
        r++;

        while(r!=R.end()){
            if(r->si>f){
                A.push_back(*r);
                f=r->fi;
            }
            r++;
        }

        return A;
    }

    void ShowRequest(std::vector<Request> R){
        std::cout<<"Set of request, begin and end:\n";
        for(auto r:R)std::cout<<r.si<<" "<<r.fi<<std::endl;
    }
}