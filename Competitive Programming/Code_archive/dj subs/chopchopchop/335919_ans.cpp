// ans.cpp 11 Mar 18, 23:02:31 90.91 0.11 Judging completed in 7.066s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long ps[1000005],cmax=INT_MIN;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long arr[1000005],arr2[1000005],n,k,maxi=INT_MIN,mini=INT_MAX;
    cin>>n>>k;
    for(int x=1;x<=n;x++){
        cin>>arr[x];arr2[x]=arr[x];
        ps[x]=ps[x-1]+arr[x];
    }
    for(int x=n-1;x>0;x--){
        arr[x]=min(arr[x],arr[x+1]);
        arr2[x]=max(arr2[x],arr2[x+1]);
    }
    arr[n+1]=INT_MAX;
    arr2[n+1]=INT_MIN;
    for(int x=n-k;x<=n;x++){
        maxi=max(max(ps[x]-ps[x-(n-k)],max(cmax,arr2[x+1]))-min(min(mini,arr[x+1]),ps[x]-ps[x-(n-k)]),maxi);
        mini=min(mini,ps[x-(n-k)+1]-ps[x-(n-k)]);
        cmax=max(cmax,ps[x-(n-k)+1]-ps[x-(n-k)]);
    }
    cout<<maxi;
    return 0;
}