// ans.cpp 11 Feb 17, 16:24:08 0 1 Judging completed in 7.625s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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