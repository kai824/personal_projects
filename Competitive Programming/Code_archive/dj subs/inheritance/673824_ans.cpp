// ans.cpp 5 Jan 20, 15:46:43 100 0.23 Judging completed in 4.52s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pair<pii,pii> > v;

int ans[300005];

int parent[10001][1005];
int getr(int x,int s){//s specifies which tree
    if(parent[s][x]==0)return x;
    parent[s][x]=getr(parent[s][x],s);
    return parent[s][x];
}
inline bool merge(int a,int b,int s){
    a=getr(a,s);b=getr(b,s);
    if(a==b)return false;
    parent[s][a]=b;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k,a,b,c;
    int lo,hi,mid;
    cin>>n>>m>>k;
    for(int x=0;x<m;x++){
        cin>>a>>b>>c;
        v.emplace_back(make_pair(c,x),make_pair(a,b));
    }
    sort(v.begin(),v.end(),greater<pair<pii,pii> >());
    for(int x=0;x<m;x++){
        lo=1;hi=k;
        if(getr(v[x].second.first,k)==getr(v[x].second.second,k))continue;
        while(lo<hi){
            mid=lo+(hi-lo)/2;
            if(getr(v[x].second.first,mid)==getr(v[x].second.second,mid)){
                lo=mid+1;
            }else hi=mid;
        }
        ans[v[x].first.second]=lo;
        merge(v[x].second.first,v[x].second.second,lo);
    }
    for(int x=0;x<m;x++){
        cout<<ans[x]<<'\n';
    }
    return 0;
}