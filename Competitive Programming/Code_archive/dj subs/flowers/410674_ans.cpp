// ans.cpp 12 Nov 18, 13:56:38 100 0.07 Judging completed in 3.307s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005];
ll ps[1000005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll k,d,a,b,ans;
    cin>>k>>d;
    arr[0]=0;
    for(int x=1;x<=1000000;x++){
        if(x<k){
            arr[x]=1;
            continue;
        }else if(x==k){
            arr[x]=2;
            continue;
        }
        arr[x]=arr[x-1];
        if(x>=k)arr[x]+=arr[x-k];
        arr[x]%=1000000000+7;
    }
    for(int x=1;x<=1000000;x++){
        ps[x]=ps[x-1]+arr[x];
        ps[x]%=1000000000+7;
    }
    for(int x=0;x<d;x++){
        cin>>a>>b;
        ans=ps[b]-ps[a-1];
        ans%=1000000000+7;
        if(ans<0)ans+=1000000000+7;
        cout<<ans<<'\n';
    }
    return 0;
}