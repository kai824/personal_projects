// ans.cpp 22 Nov 20, 23:29:31 9.52 0.63 Judging completed in 5.276s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
//#define int long long
int pa[600005];
bool overthrown[600005];

priority_queue<pair<int,int> > pq[600005];

int getr(int x){
    if(pa[x]==-1)return x;
    pa[x]=getr(pa[x]);
    return pa[x];
}
inline bool merge(int a,int b){
    if(overthrown[a]||overthrown[b])return true;
    a=getr(a);
    b=getr(b);
    if(a==b)return true;
    if(pq[a].size()<pq[b].size())swap(a,b);
    
    pa[b]=a;
    while(pq[b].size()>0){
        pq[a].push(pq[b].top());
        pq[b].pop();
    }
    cout<<pq[a].top().second<<'\n';
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a,b;
    cin>>n>>k;
    for(int x=1;x<=n;x++){
        cin>>a;
        pq[x].emplace(a,x);
        pa[x]=-1;
    }
    for(int x=0;x<k;x++){
        cin>>a>>b;
        if(a==-1){
            if(overthrown[b]){
                cout<<"-1\n";
                continue;
            }
            b=getr(b);
            if(pq[b].size()==1)cout<<"-1\n";
            else{
                overthrown[pq[b].top().second]=true;
                pq[b].pop();
                cout<<pq[b].top().second<<'\n';
            }
        }else{
            if(merge(a,b)){
                cout<<"-1\n";
            }
        }
    }
    return 0;
}