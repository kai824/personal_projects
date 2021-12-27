// ans.cpp 18 Nov 17, 11:50:22 100 0.49 Judging completed in 3.968s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[50005],rankk[50005],ans[50005];
int net[50005],max_connect=0;//tinyurl.com/y8n7fmaz
int get_root(int x){
	if(parent[x]==-1) return x;
	else parent[x]=get_root(parent[x]);
	return parent[x];
}
void merge(int A,int B){
    if(get_root(A)==get_root(B))return;
	if(rankk[A]<rankk[B]){
		net[get_root(B)]+=net[get_root(A)];
		parent[get_root(A)]=get_root(B);
		max_connect=max(max_connect,net[get_root(B)]);
	}else if(rankk[B]<rankk[A]){
		net[get_root(A)]+=net[get_root(B)];
		parent[get_root(B)]=get_root(A);
		max_connect=max(max_connect,net[get_root(A)]);
	}else {
		net[get_root(B)]+=net[get_root(A)];
		parent[get_root(A)]=get_root(B);
		max_connect=max(max_connect,net[get_root(B)]);
		rankk[get_root(B)]+=1;
	}
	
}
bool checkifconnected(int a,int b){
    return(get_root(a)==get_root(b));
}
bool cmp(pair<int,pair<int,int> >a,pair<int,pair<int,int> >b){
	return(a.first>b.first);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill_n(parent,50005,-1);
    fill_n(ans,50005,-1);
    fill_n(net,50005,1);
    int v,e,q,a,b,c;
    vector<pair<int,pair<int,int> > > el;
    cin>>v>>e>>q;
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        el.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(el.begin(),el.end(),cmp);
    for(int x=0;x<el.size();x++){
        merge(el[x].second.first,el[x].second.second);
        ans[max_connect]=max(ans[max_connect],el[x].first);
    }
    for(int x=v-1;x>=0;x--){
		ans[x]=max(ans[x],ans[x+1]);
    }
    for(int x=0;x<q;x++){
    	cin>>a;
    	cout<<ans[a]<<'\n';
    }
    return 0;
}