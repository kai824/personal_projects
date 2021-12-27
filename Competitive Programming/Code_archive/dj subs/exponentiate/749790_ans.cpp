// ans.cpp 20 Jul 20, 21:58:03 100 0.07 Judging completed in 3.543s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#define int long long

int m;

int expo(int a,int b){
    int ans=1,s=a;
    for(int i=0;i<22;i++){
        if((1ll<<i)&b){
            ans*=s;
            ans%=m;
        }
        s=(s*s)%m;
        if((1ll<<i)>b)break;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int q,a,b;
    cin>>q;
    while(q--){
        cin>>a>>b>>m;
        cout<<expo(a,b)<<'\n';
    }
    return 0;
}