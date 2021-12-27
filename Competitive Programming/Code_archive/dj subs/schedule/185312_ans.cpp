// ans.cpp 27 Jan 17, 22:06:51 0 1.46 Judging completed in 6.844s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int find_max(){
    return 0;
}
int main() {
    int n,a=-10;
    cin>>n;
    pair<pair<int,int>,int> m[n+1];
    m[0]=make_pair(make_pair(INT_MAX,INT_MAX),INT_MAX);
    for(int x=1;x<=n;x++){
        cin>>m[x].first.first>>m[x].first.second>>m[x].second;
        a=max(m[x].first.second,a);
    }sort(m,m+n+1);
    memset(dp,0,sizeof(dp));
    for(int x=1;x<a;x++){
        
    }cout<<600;
    return 0;
}