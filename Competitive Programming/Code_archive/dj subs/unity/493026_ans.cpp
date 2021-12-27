// ans.cpp 18 Feb 19, 10:44:06 70 1.02 Judging completed in 3.567s on AWS Oregon.
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
    vector<pair<int,pair<int,int> > > roads;
    pair<int,pair<int,int> > to_push;
    for(int x=0;x<bb;x++){
        cin>>to_push.second.first>>to_push.second.second>>to_push.first;
        if(connected(to_push.second.first,to_push.second.second)){
            continue;
        }
        roads.push_back(to_push);
    }
    sort(roads.begin(),roads.end());
    for(int x=0;x<roads.size();x++){
        if(connected(roads[x].second.first,roads[x].second.second)==false){
            merge(roads[x].second.first,roads[x].second.second);
            ans+=roads[x].first;
        }
    }
    cout<<ans;
    return 0;
}