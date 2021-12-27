// ans.cpp 1 Mar 20, 16:33:52 90.91 0.07 Judging completed in 3.157s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#define int long long

int ps[1000055];
int pmin[1000055],bmin[1000055];//prefix min, back min
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    bmin[n+1]=pmin[0]=LLONG_MAX;
    for(int x=1;x<=n;x++){
        cin>>ps[x];
        pmin[x]=min(ps[x],pmin[x-1]);
        ps[x]+=ps[x-1];
    }
    pmin[n+1]=pmin[n];
    for(int x=n;x>=1;x--){
        bmin[x]=min(bmin[x+1],ps[x]-ps[x-1]);
    }bmin[0]=bmin[1];
    for(int x=n-k;x<=n;x++){
        ans=max(ans,abs(ps[x]-ps[x-(n-k)] - min(bmin[x+1],pmin[x-(n-k)])) );
    }
    if(ans==0)while(true);;
    cout<<ans<<'\n';
    return 0;
}