// ans.cpp 24 Nov 18, 23:39:24 0 0.12 Judging completed in 7.745s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a,ans=0;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    int ps[n+1];
    ps[0]=0;
    for(int x=1;x<=n;x++){
        cin>>a;
        a=k-a;
        ps[x]=ps[x-1]+a;
    }
    pair<ll,ll> tmp;
    unordered_map<ll,pair<ll,ll> >dp;//prefix sum value, index, dp value
    for(int x=0;x<=n;x++){
        if(dp.find(ps[x])==dp.end()){//does not exist yet
            dp[ps[x]]=make_pair(x,ans);
        }else{
            tmp=dp[ps[x]];
            ans=max(ans,tmp.second+((x-tmp.first)*k));
            if(ans>tmp.second+((x-tmp.first)*k)){
                //using the new value more optimal...
                dp[ps[x]]=make_pair(x,ans);
            }
        }
    }
    cout<<ans;
    return 0;
}