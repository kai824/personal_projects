// ans.cpp 11 Mar 18, 22:44:06 90.91 0.08 Judging completed in 7.374s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long ps[1000005],ans=0,mini=INT_MAX;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long arr[1000005],n,k,maxi=0,mini=INT_MAX;
    cin>>n>>k;
    if(k==0){
        cout<<0;
        return 0;
    }
    for(int x=1;x<=n;x++){
        cin>>arr[x];
        ps[x]=ps[x-1]+arr[x];
    }
    for(int x=n-1;x>0;x--){
        arr[x]=min(arr[x],arr[x+1]);
    }
    arr[n+1]=INT_MAX;
    for(int x=n-k;x<=n;x++){
        maxi=max((ps[x]-ps[x-(n-k)])-min(mini,arr[x+1]),maxi);
        mini=min(mini,ps[x-(n-k)+1]-ps[x-(n-k)]);
    }
    cout<<maxi;
    return 0;
}