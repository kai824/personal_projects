// ans.cpp 21 Mar 18, 20:29:21 0 0.09 Judging completed in 5.165s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bitset<1000003>f;
long long factors[1000003];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,ans=0,u;
    cin>>n;
    f[1]=1;
    for(int x=1;x<=n;x++){
        u=x*x;
        if(f[x]==0){
            while(0<u&&u<=n){
                if(u>n/* || u<=0*/)while(true){}
                f[u]=1;
                u*=x;
            }
        }
        
        u=x;
        while(u<=n && x!=1){
            factors[u]++;
            u+=x;
        }
        //cout<<f[x-factors[x]]<<'\n';
        if(x-factors[x]<0){
          cout<<x;
          break;
        }
        if(f[x-factors[x]]==1){
          //cout<<x<<' ';
            ans+=x-factors[x];
            ans%=(1000000007);
            //cout<<ans<<'\n';
        }
        //cout<<x<<' ';
    }
    cout<<ans;
    return 0;
}