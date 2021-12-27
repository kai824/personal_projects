// ans.cpp 8 Feb 18, 09:52:07 100 0.04 Judging completed in 5.295s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll costs[17];
ll adjmat[17][105][105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,q,t[4],ui,ei,vi,ti,s,e,ans;
    string T;
    cin>>n>>m>>q;
    cin>>t[0]>>t[1]>>t[2]>>t[3];
    for(ll i=1;i<=16;i++){
        for(ll y=0;y<4;y++){
            if((i&(1<<y))!=0){
                costs[i]+=t[y];
            }
        }
        
        for(ll y=0;y<105;y++){
            for(ll z=0;z<105;z++){
                adjmat[i][y][z]=LLONG_MAX-1000000005;
                if(y==z)adjmat[i][y][z]=0;
            }
        }
    }
    for(ll x=0;x<m;x++){
        cin>>ui>>ei>>vi>>T;
        if(T=="ground")ti=0;
        else if(T=="water")ti=1;
        else if(T=="grass")ti=2;
        else ti=3;
        for(ll i=1;i<=16;i++){
            if((i&(1<<ti))!=0){
                adjmat[i][ui][ei]=min(adjmat[i][ui][ei],vi);
                adjmat[i][ei][ui]=min(adjmat[i][ei][ui],vi);
            }
        }
    }
    for(ll x=1;x<16;x++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                for(ll k=1;k<=n;k++){
                    adjmat[x][j][k]=min(adjmat[x][j][k],adjmat[x][j][i]+adjmat[x][i][k]);
                }
            }
        }
    }
    for(ll x=0;x<q;x++){
        cin>>s>>e;
        ans=LLONG_MAX-1000000005;
        for(ll i=1;i<=16;i++){
            ans=min(ans,min(adjmat[i][s][e],adjmat[i][e][s])+costs[i]);
        }
        if(ans==LLONG_MAX-1000000005)cout<<"-1\n";
        else cout<<ans<<'\n';
    }
    return 0;
}