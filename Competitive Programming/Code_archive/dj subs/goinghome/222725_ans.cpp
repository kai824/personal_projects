// ans.cpp 16 Oct 17, 11:38:26 100 0.55 Judging completed in 4.613s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,s,r,a,b,c;
    cin>>n>>s>>r;
    int dp[n+1];
    vector<pair<int,int> >/*Stores the starting point and cost*/ arr[n+1];
    for(int x=0;x<s;x++){
        cin>>a>>b>>c;
        if(a!=b)arr[b].push_back(make_pair(a,c));
    }
    for(int x=0;x<n;x++){dp[x]=0;}
    dp[0]=0;
    for(int x=1;x<=n;x++){
        a=dp[x-1]+r;
        for(int y=0;y<arr[x].size();y++){
            a=min(a,arr[x][y].second+dp[arr[x][y].first]);
        }
        dp[x]=a;
    }
    cout<<dp[n];
    return 0;
}