// ans.cpp 23 Dec 19, 17:03:11 100 0.39 Judging completed in 4.854s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[50];
vector<ll> v1,v2;
int main(){
    ll n,m,cur,ans=0;
    ll lo,hi,mid;
    cin>>n>>m;
    for(ll x=0;x<n;x++){
        cin>>arr[x];
    }
    for(ll x=0;x<(1<<min(20ll,n));x++){
        cur=0;
        for(ll i=0;i<20;i++){
            if( ((1<<i)&x)==0)continue;
            cur+=arr[i];
        }
        if(cur<=m)v1.push_back(cur);
    }
    if(n<=20){
        cout<<v1.size();
        return 0;
    }
    for(ll x=0;x<(1<<min(20ll,n-20));x++){
        cur=0;
        for(ll i=0;i<20;i++){
            if( ((1<<i)&x)==0)continue;
            cur+=arr[i+20];
        }
        if(cur<=m)v2.push_back(cur);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(ll x=0;x<v1.size();x++){
        lo=0;hi=v2.size()-1;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(v1[x]+v2[mid]<=m){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        ans+=lo+1;
    }
    cout<<ans;
    return 0;
}
/*
5 1000
100 1500 500 500 1000
*/