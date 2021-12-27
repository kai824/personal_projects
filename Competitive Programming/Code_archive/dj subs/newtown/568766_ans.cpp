// ans.cpp 26 Oct 19, 21:11:30 0 1.15 Judging completed in 5.316s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int parent[1000005];

int get_root(int x){
    if(parent[x]==-1)return x;
    parent[x]=get_root(parent[x]);
    return parent[x];
}
inline void merge(int a,int b){
    if(get_root(a)==get_root(b))return;
    parent[get_root(a)]=get_root(b);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long ans=0,n,e;
    cin>>n>>e;
    pair<int,pair<int,int> > el[e];//edge_list
    for(int x=0;x<e;x++){
        cin>>el[x].second.first>>el[x].second.second>>el[x].first;
    }
    sort(el,el+e);
    for(int x=0;x<e;x++){
        if(get_root(el[x].second.first)!=get_root(el[x].second.second)){
            merge(el[x].second.first,el[x].second.second);
            ans+=el[x].first;
        }
    }
    cout<<ans;
    return 0;
}