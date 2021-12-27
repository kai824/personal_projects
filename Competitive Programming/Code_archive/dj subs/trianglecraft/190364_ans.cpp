// ans.cpp 11 Feb 17, 16:22:51 0 1 Judging completed in 6.33s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,a,b;
    vector<pair<int,int> > houses;
    cin>>n>>k;
    for(int x=0;x<k;x++){
        cin>>a>>b;
        houses.push_back(make_pair(a,b));
    }
    a=0;//now used as ans...
    for(int x=0;x<k;x++){
        for(int y=x+1;y<k;y++){
            a+=abs(houses[x].first-houses[y].first)+abs(houses[x].second-houses[y].second)-1;
        }
    }
    cout<<a;
    return 0;
}