// ans.cpp 29 Mar 17, 19:25:01 100 0.31 Judging completed in 5.684s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int parent[1000000],rank[1000000];
int get_root(int x){
	if(parent[x]==x) return x;
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,e,a,b;
    vector<int>stuff;
    cin>>n>>e;
    for(int x=0;x<n;x++){
        parent[x]=x;
    }
    for(int x=0;x<e;x++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        merge(a,b);
    }
    for(int x=0;x<n;x++){
        stuff.push_back(get_root(x));
    }
    sort(stuff.begin(),stuff.end());
    stuff.erase(unique(stuff.begin(),stuff.end()),stuff.end());
    cout<<stuff.size();
    return 0;
}