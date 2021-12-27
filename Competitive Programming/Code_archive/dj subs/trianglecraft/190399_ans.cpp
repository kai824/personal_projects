// ans.cpp 11 Feb 17, 16:27:18 0 0.28 Judging completed in 6.699s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,a,b;
    cin>>n>>k;
    pair<int,int> houses[k];
    for(int x=0;x<k;x++){
        cin>>houses[x].first>>houses[x].second;
    }
    /*a=0;//now used as ans...
    for(int x=0;x<k;x++){
        for(int y=x+1;y<k;y++){
            a+=abs(houses[x].first-houses[y].first)+abs(houses[x].second-houses[y].second)-1;
        }
    }*/
    cout<<a;
    return 0;
}