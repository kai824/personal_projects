// ans.cpp 30 Nov 19, 15:06:33 100 0.11 Judging completed in 4.126s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,arr[1000005];

bool valid(ll k){
    ll cur=0,partitions=0;
    for(int x=0;x<n;x++){
        if(arr[x]>k)return false;
        if(cur+arr[x]<=k){
            cur+=arr[x];
        }else{
            cur=arr[x];//new partition...
            partitions++;
            if(partitions>m)return false;
        }
    }
    if(cur>0)partitions++;
    if(partitions>m)return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    ll lo=0,hi=n*1e6,mid;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(valid(mid)){
            hi=mid;
        }else lo=mid+1;
    }
    cout<<lo;
    return 0;
}