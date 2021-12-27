// ans.cpp 18 Feb 19, 10:40:40 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[10005];
int get_root(int x){
	if(parent[x]==-1) return x;
	else parent[x]=get_root(parent[x]);
	return parent[x];
}
inline void merge(int A,int B){
	if(original[get_root(A)]>original[get_root(B)])swap(A,B);
	parent[get_root(A)]=B;
}
inline bool connected(int a,int b){
    return(get_root(a)==get_root(b));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,w,a,b,c,bb,ans=0;
    fill_n(parent,100005,-1);
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