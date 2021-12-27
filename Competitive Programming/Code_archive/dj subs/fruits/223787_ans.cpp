// ans.cpp 18 Oct 17, 23:08:10 0 0.14 Judging completed in 4.459s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,k,ans=0,xx;
    cin>>n>>k;
    ll e[n],g[n];
    deque<pair<ll,ll> > lo;//leftovers
    //number, number of days left
    for(ll x=0;x<n;x++){
        cin>>g[x];
    }
    for(ll x=0;x<n;x++){
        cin>>e[x];
    }
    
    for(ll x=0;x<n;x++){
        for(ll y=0;x<lo.size();){
            lo[y].second--;
            if(lo[y].second<0)lo.pop_front();
            else y++;
        }
        lo.push_back(make_pair(g[x],k));
        for(ll y=0;(y<lo.size() && e[x]>0);){
                if(lo[y].first<=e[x]){
                    e[x]-=lo[y].first;
                    ans+=lo[y].first;
                    lo.pop_front();
                }else{//lo[y].first>e[x]
                    lo[y].first-=e[x];
                    ans+=e[x];
                    e[x]=0;
                }
        }
    }
    cout<<ans;
    return 0;
}