// ans.cpp 1 Mar 20, 16:26:05 90.91 0.08 Judging completed in 3.259s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#define int long long

int ps[1000005];
int pmin[1000005],bmin[1000005];//prefix min, back min
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    if(k==0)while(true){};
    bmin[n+1]=pmin[0]=LLONG_MAX;
    for(int x=1;x<=n;x++){
        cin>>ps[x];
        pmin[x]=min(ps[x],pmin[x-1]);
        ps[x]+=ps[x-1];
    }
    for(int x=n;x>=1;x--){
        bmin[x]=min(bmin[x+1],ps[x]-ps[x-1]);
    }
    for(int x=n-k;x<=n;x++){
        ans=max(ans,ps[x]-ps[x-(n-k)] - min(bmin[x+1],pmin[x-(n-k)]) );
    }
    cout<<ans<<'\n';
    return 0;
}