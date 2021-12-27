// ans.cpp 17 Feb 19, 17:43:32 30 1 Judging completed in 3.86s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
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
            if(heights[e]>heights[d]){
                if((costs[e]+((d-e)*(d-e)))<rmin) rmin=(costs[e]+((d-e)*(d-e)));
            }
        }
        costs.push_back(rmin);
    }
    cout<<costs.back();
    return 0;
}