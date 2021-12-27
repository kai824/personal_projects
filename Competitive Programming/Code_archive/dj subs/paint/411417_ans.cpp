// ans.cpp 12 Nov 18, 21:51:43 100 0 Judging completed in 2.471s on AWS Oregon.
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