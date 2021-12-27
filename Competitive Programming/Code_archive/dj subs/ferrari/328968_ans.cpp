// ans.cpp 22 Feb 18, 09:44:45 0 3 Judging completed in 8.014s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,ans=1,a,b=1;
    cin>>n;
    ll arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr[x]++;
    }
    for(int x=0;x<n;x++){
        for(int y=x+1;y<n;y++){
            a=__gcd(arr[x],arr[y]);
            arr[x]/=a;arr[y]/=a;
            b*=a;
            b%=1000000007;
            if(arr[x]==1)break;
        }
        ans*=arr[x];
        ans%=(1000000007);
    }
    ans*=b;
    ans%=1000000007;
    cout<<ans-1;
    return 0;
}