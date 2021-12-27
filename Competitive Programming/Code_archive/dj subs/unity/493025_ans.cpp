// ans.cpp 18 Feb 19, 10:42:22 70 0.17 Judging completed in 2.896s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma Ospace
int parent[10005];
int get_root(int x){
	if(parent[x]==-1) return x;
	else parent[x]=get_root(parent[x]);
	return parent[x];
}
inline void merge(int A,int B){
	parent[get_root(A)]=B;
}
inline bool connected(int a,int b){
    return(get_root(a)==get_root(b));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,w,a,b,c,bb,ans=0;
    for(int x=0;x<10005;x++){
        parent[x]=-1;
    }
    cin>>n>>w;
    for(int x=0;x<w;x++){
        cin>>a>>b;
        merge(a,b);
    }
    cin>>bb;
    pair<int,pair<int,int> > roads[bb];
    for(int x=0;x<bb;x++){
        cin>>roads[x].second.first>>roads[x].second.second>>roads[x].first;
    }
    sort(roads,roads+bb);
    for(int x=0;x<bb;x++){
        if(connected(roads[x].second.first,roads[x].second.second)==false){
            merge(roads[x].second.first,roads[x].second.second);
            ans+=roads[x].first;
        }
    }
    cout<<ans;
    return 0;
}