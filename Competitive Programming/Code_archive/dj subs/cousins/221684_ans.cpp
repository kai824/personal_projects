// ans.cpp 7 Oct 17, 21:51:52 100 0.28 Judging completed in 4.744s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trinum(ll x){
    return ((x*(x+1))/2);
}
int main() {
    ll n,prev=0,ans=0;
    cin>>n;
    string arr[n];
    for(ll x=0;x<n;x++){
        cin>>arr[x];
        sort(arr[x].begin(),arr[x].end());
    }
    sort(arr,arr+n);
    for(ll x=1;x<n;x++){
        if(arr[x]!=arr[x-1]){
            ans+=trinum(x-prev-1);
            prev=x;
        }
    }
    ans+=trinum(n-prev-1);
    cout<<ans;
    return 0;
}