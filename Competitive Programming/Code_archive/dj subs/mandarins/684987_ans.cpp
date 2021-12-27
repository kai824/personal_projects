// ans.cpp 24 Jan 20, 16:36:38 14 0 Judging completed in 3.575s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ipow(ll a,ll b,ll m){
    ll current,ans=1;
    for(int y=19;(y>=0 && b>0);y--){
        current=a;
        if(pow(2,y)>b)continue;
        for(int z=0;z<y;z++){
            current=current*current;
            current=current%m;
        }
        current=current%m;
        ans*=current;
        ans=ans%m;
        b-=pow(2,y);
    }
    return ans;
}
int main() {
    ll n,k;cin>>n>>k;
    k++;
    //calculate k power n...
    cout<<ipow(k,n,1e9+7);
    return 0;
}