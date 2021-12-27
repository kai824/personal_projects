// ans.cpp 31 Jan 19, 23:08:04 100 0.01 Judging completed in 2.05s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,l,ans=0;//l for limit
    cin>>n>>l;
    ll arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    for(int x=1;x<n;x++){
        if(arr[x]+arr[x-1]>l){
            ans+=(arr[x]+arr[x-1])-l;
            arr[x]-=(arr[x]+arr[x-1])-l;
            if(arr[x]<0){
                arr[x-1]+=arr[x];
                arr[x]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}