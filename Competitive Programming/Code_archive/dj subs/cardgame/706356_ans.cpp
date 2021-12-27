// ans.cpp 28 Feb 20, 22:43:43 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2][3005],ps[3005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    bool bit=1;
    ll n,k,l,ans=0,max;
    deque<pair<ll,ll> > dq;//sliding range max query
    cin>>n>>k>>l;
    for(int i=1;i<=n;i++){
        cin>>a;
        ps[i]=ps[i-1]+a;
    }
    for(int x=1;x<=k;x++){
        dq.clear();dq.push_back(make_pair(0,0));
        for(int i=1;i<=n;i++){
            while(dq.front().second+l<i){
                dq.pop_front();
            }
            dp[bit][i]=dq.front().first+ps[i];
            ans=max(ans,dp[bit][i]);
            while(dq.size()>0 && dq.back().first<=dp[!bit][i]-ps[i]){
                dq.pop_back();
            }
            dq.push_back(make_pair(dp[!bit][i]-ps[i],i));
        }
        bit=!bit;
    }
    cout<<ans;
    return 0;
}