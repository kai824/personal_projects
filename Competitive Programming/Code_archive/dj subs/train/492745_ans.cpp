// ans.cpp 17 Feb 19, 17:54:32 0 1 Judging completed in 5.674s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,rmin;
    vector<int> heights;
    vector<int> costs;
    heights.push_back(1000000000);
    costs.push_back(0);
    cin>>a;
    for(int d=0;d<a;d++){
        cin>>b;
        heights.push_back(b);
    }
    heights.push_back(0);
    for(int d=1;d<=(a+1);d++){
        rmin=1000000000;
        for(int e=d-1;e>=0;e--){
            if(heights[e]>=heights[d]){
                if(heights[e]==heights[d]){
                    while(true){}
                }
                if((costs[e]+((d-e)*(d-e)))<rmin) rmin=(costs[e]+((d-e)*(d-e)));
            }
        }
        costs.push_back(rmin);
    }
    cout<<costs.back();
    return 0;
}