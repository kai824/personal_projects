// ans.cpp 13 Oct 17, 10:40:14 0 0 Judging completed in 3.109s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,m,a,b;
    cin>>n>>m;
    bool arr[n];
    memset(arr,false,sizeof(arr));
    vector<ll> c[n+1];//1-indexed.
    for(ll x=0;x<m;x++){
        cin>>a>>b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    deque<ll> bfs,bfs2;
    bfs.push_back(1);
    for(ll x=0;x<c[1].size();x++){
        bfs.push_back(c[1][x]);
        arr[c[1][x]-1]=true;
    }
    bfs.pop_front();
    a=bfs.size();
    for(ll x=0;x<a;x++){
        for(ll y=0;y<c[bfs[x]].size();y++){
            arr[c[bfs[x]][x]-1]=true;
        }
    }
    a=0;
    for(ll x=1;x<n;x++){
    	if(arr[x])a++;
    }
    cout<<a;
    return 0;
}