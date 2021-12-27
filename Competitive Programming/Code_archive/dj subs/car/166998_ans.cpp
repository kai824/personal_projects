// ans.cpp 3 Dec 16, 14:18:20 100 1.32 Judging completed in 7.079s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int parent[1000000],rank[1000000];
int get_root(int x){
	if(parent[x]==-1) return x;
	else parent[x]=get_root(parent[x]);
	return parent[x];
}
void merge(int A,int B){
	if(rank[A]<rank[B])parent[get_root(A)]=get_root(B);
	else if(rank[B]<rank[A])parent[get_root(B)]=get_root(A);
	else {
		parent[get_root(A)]=get_root(B);
		rank[get_root(B)]+=1;
	}
}
bool checkifconnected(int a,int b){
    return(get_root(a)==get_root(b));
}
int main() {
    int n,e,a,b,d;
    cin>>n>>e;
    fill_n(parent,1000000,-1);
    vector<pair<int,pair<int,int> > > adjlist(e);//weight,endpoint1,endpoint2
    vector<int> to_use;
    for(int x=0;x<e;x++){
        cin>>a>>b>>d;
        adjlist.push_back(make_pair(d,make_pair(a,b)));
    }
    sort(adjlist.begin(),adjlist.end());
    for(int x=0;x<adjlist.size();x++){
        if(!checkifconnected(adjlist[x].second.first,adjlist[x].second.second)){
            to_use.push_back(adjlist[x].first);
            merge(adjlist[x].second.first,adjlist[x].second.second);
        }
        if(checkifconnected(1,n)) break;
    }
    cout<<to_use.back();
    return 0;
}