// ans.cpp 21 Mar 18, 20:03:19 0 0 Judging completed in 5.422s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bitset<10000003>f;
int factors[10000003];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=0,u;
    cin>>n;
    for(int x=1;x<=n;x++){
        u=x*x;
        if(f[x]==0 && x>1){
            while(u<=n){
                f[u]=1;
                u*=x;
            }
        }
        
        u=x;
        while(u<=n){
            factors[u]++;
            u+=x;
        }
        if(f[x-factors[x]]==1){
            ans+=x-factors[x];
            ans%=1000000000+7;
        }
    }
    cout<<ans;
    return 0;
}