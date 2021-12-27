// ans.cpp 2 Dec 19, 14:38:07 100 0.88 Judging completed in 7.236s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,k,ans=0;
    cin>>n>>k;
    ll ps[n+1],w[n+1];ps[0]=w[0]=0;
    for(int x=1;x<=n;x++){
        cin>>ps[x];
        ps[x]+=ps[x-1];
    }
    for(int x=1;x<=n;x++){
        cin>>w[x];
        w[x]+=w[x-1];
    }
    priority_queue<pii,vector<pii>,greater<pii> > pq;//prefix reward, weight...
    pq.push(make_pair(0,0));
    for(int x=1;x<=n;x++){
        while(!pq.empty()){
            if(w[x]-pq.top().second>k){
                pq.pop();
            }else break;
        }
        if(!pq.empty())ans=max(ans,ps[x]-pq.top().first);
        pq.push(make_pair(ps[x],w[x]));
    }
    cout<<ans;
    return 0;
}