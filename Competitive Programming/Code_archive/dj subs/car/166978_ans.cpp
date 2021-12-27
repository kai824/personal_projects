// ans.cpp 3 Dec 16, 14:09:41 50 1.74 Judging completed in 7.471s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int parent[1000000];
bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return(a.first<b.first);
}
int get_root(int x){
	if(parent[x]==-1) return x;
	else parent[x]=get_root(parent[x]);
	return parent[x];
}
void merge(int a,int b){
	parent[get_root(a)]=get_root(b);
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
    a=0;//a is now the cost
    sort(adjlist.begin(),adjlist.end(),cmp);
    for(int x=0;x<adjlist.size();x++){
        if(!checkifconnected(adjlist[x].second.first,adjlist[x].second.second)){
            a+=adjlist[x].first;
            to_use.push_back(adjlist[x].first);
            merge(adjlist[x].second.first,adjlist[x].second.second);
        }
        if(checkifconnected(1,n)) break;
    }
    cout<<to_use.back();
    return 0;
}