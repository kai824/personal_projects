// ans.cpp 18 Oct 17, 16:07:00 10 0 Judging completed in 5.462s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1000000000000;
ll coins[9]={1,5,10,50,100,500,1000,5000,10000};//and 17
void g(ll a,ll b,ll c){
    //amount, next coin to use, amt of coins used...
    for(ll x=b;x>=0;x--){
        c+=(a/coins[x]);
        a%=coins[x];
    }
    ans=min(ans,c);
    return;
}
int main(){
    ll n,u=0;
    cin>>n;
    for(ll x=8;x>=0;x--){
        g(n,x,u);
        g(n%17,x,u+(n/17));
        u+=(n/coins[x]);
        n%=coins[x];
    }
    cout<<ans;
    return 0;
}