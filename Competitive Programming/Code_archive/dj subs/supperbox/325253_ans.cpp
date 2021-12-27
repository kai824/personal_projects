// ans.cpp 11 Feb 18, 15:47:32 14 2.17 Judging completed in 6.54s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[10005],s[10005],a,b,x;//weight, value
ll knapsack[10005][2005];
ll val(ll id, ll remW){
    if(remW==0)return 0;
    if(id>=b+1)return 0;
    if(c[id]>remW){
    if(knapsack[id][remW]==-1)knapsack[id][remW]=val(id+1,remW);
        return(knapsack[id][remW]);
    }
    if(knapsack[id][remW]==-1)knapsack[id][remW]=max(val(id+1,remW),s[id]+val(id+1,remW-c[id]));
    return knapsack[id][remW];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>c[i]>>s[i];//calories, satisfaction...
    }
    cin>>q;
    for(ll i=0;i<q;i++){
        cin>>a>>b>>x;
        for(ll y=a;y<=b+3;y++){
            for(ll z=0;z<2005;z++){
                knapsack[y][z]=-1;
            }
        }
        cout<<val(a,x)<<'\n';
    }
    return 0;
}