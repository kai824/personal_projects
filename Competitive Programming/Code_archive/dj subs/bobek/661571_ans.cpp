// ans.cpp 23 Dec 19, 16:58:00 40 0.22 Judging completed in 5.363s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[50];
vector<ll> v1,v2;
int main(){
    ll n,m,cur,ans=0;
    ll lo,hi,mid;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    for(int x=0;x<(1<<min(20ll,n));x++){
        cur=0;
        for(int i=0;i<20;i++){
            if( ((1<<i)&x)==0)continue;
            cur+=arr[i];
        }
        if(cur<=m)v1.push_back(cur);
    }
    if(n<=20){
        cout<<v1.size();
        return 0;
    }
    for(int x=0;x<(1<<min(20ll,n-20));x++){
        cur=0;
        for(int i=0;i<20;i++){
            if( ((1<<i)&x)==0)continue;
            cur+=arr[i+20];
        }
        if(cur<=m)v2.push_back(cur);
    }
    for(int x=0;x<v1.size();x++){
        if(v1[x]+v2[0]>m){
            continue;
        }
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