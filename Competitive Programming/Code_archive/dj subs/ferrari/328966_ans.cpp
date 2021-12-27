// ans.cpp 22 Feb 18, 09:38:25 0 3 Judging completed in 13.723s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,ans=1,a;
    cin>>n;
    ll arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr[x]++;
    }
    for(int x=0;x<n;x++){
        for(int y=x+1;y<n;y++){
            arr[x]/=__gcd(arr[x],arr[y]);
        }
        ans*=arr[x];
        ans%=(1000000007);
    }
    if(ans==0)ans+=1000000007;
    cout<<ans-1;
    return 0;
}