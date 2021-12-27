// ans.cpp 26 Dec 17, 14:19:40 100 0.48 Judging completed in 4.961s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll hft[2005][2005];
ll vft[2005][2005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,q,a,b,c;
    cin>>n>>m>>q;
    for(ll x=0;x<q;x++){
        cin>>a;
        if(a==0){
            cin>>a>>b>>c;
            if(b>c)swap(b,c);
            hft[a][b]++;
            hft[a][c+1]--;
        }else{
            cin>>a>>b>>c;
            if(b>c)swap(b,c);
            vft[a][b]++;
            vft[a][c+1]--;
        }
    }
    ll maxi=0,cnt=0;
    for(ll x=1;x<=n;x++){
        ll current=0;
        for(ll y=1;y<=m;y++){
            current+=hft[x][y];
            vft[y][x]+=vft[y][x-1];
            if(current+vft[y][x]>maxi){
                maxi=current+vft[y][x];
                cnt=1;
            }else if(current+vft[y][x]==maxi){
                cnt++;
            }
        }
    }
    cout<<maxi*cnt;
    return 0;
}