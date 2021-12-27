// ans.cpp 2 Oct 17, 07:24:57 40 3.01 Judging completed in 8.852s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dp[1000005],a=-1,n;
pair<pair<int,int>,int> m[1000005];
int find_max(int x,int N){
    int ans=-1,b;
    for(int y=0;y<N+1;y++){
        if(m[y].first.second==x){
            ans=max(ans,m[y].second+dp[m[y].first.first]);
        }else if(m[y].first.second<x){
            return ans;
        }
    }
    return -1;
}
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return(a.first.second>b.first.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>m[x].first.first>>m[x].first.second>>m[x].second;
        a=max(m[x].first.second,a);
    }sort(m,m+n,cmp);
    for(int x=2;x<=a;x++){
        dp[x]=max(dp[x-1],find_max(x,n));
    }
    cout<<dp[a];
    return 0;
}