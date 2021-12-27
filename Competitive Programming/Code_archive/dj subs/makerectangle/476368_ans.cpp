// ans.cpp 11 Jan 19, 21:32:26 100 0.02 Judging completed in 2.627s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a1=0,a2=0;
    cin>>n;
    ll arr[n];
    for(ll x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    for(ll x=1;x<n;x++){
        if(arr[x]==arr[x-1]){
            if(arr[x]>a1){
                a2=a1;
                a1=arr[x];
            }else if(arr[x]>a2){
                a2=arr[x];
            }
            x++;
        }
    }
    cout<<a1*a2;
    return 0;
}