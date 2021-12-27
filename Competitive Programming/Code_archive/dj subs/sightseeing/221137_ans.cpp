// ans.cpp 29 Sep 17, 07:51:52 0 1.78 Judging completed in 8.682s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[300005],rank[300005];
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return(a.second>b.second);
}
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<pair<int,int>,int> > edge_list;
    int n,e,q,a,b,c;
    cin>>n>>e>>q;
    memset(parent,-1,sizeof(parent));
    int output[q],input[q];
    fill_n(output,q,INT_MAX);
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        edge_list.push_back(make_pair(make_pair(a,b),c));
    }
    sort(edge_list.begin(),edge_list.end(),cmp);
    for(int x=0;x<q;x++){
        cin>>a;
        input[x]=a;
    }
    for(int x=0;x<edge_list.size();x++){
        a=edge_list[x].second;
        merge(edge_list[x].first.second-1,edge_list[x].first.first-1);
        for(int y=0;y<q;y++){
            if(output[y]==INT_MAX && checkifconnected(1,input[y]-1))output[y]=a;
        }
    }
    for(int x=0;x<q;x++){
        cout<<output[x]<<'\n';
    }
    return 0;
}