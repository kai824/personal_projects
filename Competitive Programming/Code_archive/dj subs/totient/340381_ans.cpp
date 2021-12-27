// ans.cpp 21 Mar 18, 19:46:04 0 1 Judging completed in 5.187s on AWS Oregon.
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
                f[x]=1;
                u*=x;
            }
        }
        
        if(f[x-factors[x]]==1){
            ans+=x-factors[x];
            ans%=1000000000+7;
        }
        u=x;
        while(u<=n){
            factors[u]++;
            u+=x;
        }
    }
    cout<<ans;
    return 0;
}