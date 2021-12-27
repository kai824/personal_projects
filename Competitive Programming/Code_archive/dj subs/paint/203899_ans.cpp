// ans.cpp 9 Apr 17, 21:27:01 100 0 Judging completed in 4.228s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool cmp(pii a,pii b){
    return(a.first>b.first);
}
int main() {
    int n,ans=0;
    cin>>n;
    pii costs[n];
    for(int x=0;x<n;x++){
        cin>>costs[x].second;
    }
    for(int x=0;x<n;x++){
        cin>>costs[x].first;
    }
    sort(costs,costs+n,cmp);
    for(int x=0;x<n;x++){
        ans+=costs[x].second;
        ans+=costs[x].first*(x);
    }
    cout<<ans;
    return 0;
}