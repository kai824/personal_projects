// ans.cpp 29 Oct 17, 17:47:13 100 0.02 Judging completed in 4.29s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,mini=1e18,current;
    cin>>n>>k;
    ll arr[n+5];
    for(ll x=0;x<n;x++){
        cin>>arr[x];
    }
    priority_queue<ll>pq1;
    priority_queue<ll,vector<ll>,greater<ll> > pq2;
    //trying every possible range...
    for(ll x=0;x<n;x++){//starting poll of the range...
        for(ll y=x;y<n;y++){//ending poll of range...
            while(!pq1.empty()){pq1.pop();}
            while(!pq2.empty()){pq2.pop();}
            for(ll i=0;i<x;i++){//outside the range...
                pq2.push(arr[i]);
            }
            current=0;
            for(ll i=x;i<=y;i++){
                current+=arr[i];
                pq1.push(arr[i]);
            }
            for(ll i=y+1;i<n;i++){
                pq2.push(arr[i]);
            }
            for(ll i=0;(i<k && !pq1.empty() && !pq2.empty());i++){
                mini=min(current,mini);
                current-=pq1.top();
                current+=pq2.top();
                pq1.pop();
                pq2.pop();
            }
            mini=min(current,mini);
            
        }
    }
    cout<<mini;
    return 0;
}