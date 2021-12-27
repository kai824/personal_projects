// ans.cpp 8 Sep 17, 14:46:10 0 0.04 Judging completed in 2.817s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[100005],original[100005];
int get_root(int x){
	if(parent[x]==-1) return x;
	else parent[x]=get_root(parent[x]);
	return parent[x];
}
void merge(int A,int B){
	if(original[get_root(A)]>original[get_root(B)])swap(A,B);
	parent[A]=parent[B];
}
bool checkifconnected(int a,int b){
    return(get_root(a)==get_root(b));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    fill_n(parent,100005,-1);
    int n,m,a,b;
    cin>>n>>m;
    for(int x=1;x<=n;x++){
        cin>>original[x];
    }
    for(int x=0;x<m;x++){
    cin>>a>>b;
    if(checkifconnected(a,b))cout<<-1<<'\n';
    else{
        if(original[get_root(a)]<original[get_root(b)]){
            cout<<get_root(b)<<'\n';
            parent[a]=b;
        }else{
            cout<<get_root(a)<<'\n';
            parent[b]=a;
        }
    }
    }
    return 0;
}