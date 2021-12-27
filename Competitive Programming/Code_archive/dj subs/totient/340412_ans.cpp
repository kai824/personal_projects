// ans.cpp 21 Mar 18, 20:18:57 0 0.08 Judging completed in 3.896s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bitset<1000003>f;
int factors[1000003];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=0,u;
    cin>>n;
    f[1]=1;
    for(int x=1;x<=n;x++){
        u=x*x;
        if(f[x]==0){
            while(u<=n){
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