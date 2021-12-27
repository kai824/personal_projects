// ans.cpp 29 Oct 17, 17:35:45 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,mini=ll_MAX,current;
    cin>>n>>k;
    k=min(k,n);
    ll arr[n];
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
            for(ll i=0;i<min(k,min(y-x+1,n-(y-x+1)));i++){
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