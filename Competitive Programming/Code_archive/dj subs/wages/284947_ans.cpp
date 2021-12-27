// ans.cpp 9 Dec 17, 15:14:14 100 0.3 Judging completed in 3.537s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,preorder[500005],a,b,parents[500005],nex=1;
bool visited[500005];

vector<int> adjlis[500005];
int subtree[500005];

void build(int x){//visits parents before children...
    visited[x]=true;
    preorder[x]=nex;nex++;
    for(int i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            //parents[adjlis[x][i] ]=x;
            build(adjlis[x][i]);
        }
    }
    subtree[x]=nex-1;
}

int ft[500005];
int ls(int x){
	return(x&(-x));
}
void update(int s,int e,int v){
	for(;s<=500000;s+=ls(s)){
		ft[s]+=v;
	}
	e++;
	for(;e<=500000;e+=ls(e)){
		ft[e]-=v;
	}
}
int query(int p){
	int sum=0;
	for(;p;p-=ls(p)){
		sum+=ft[p];
	}
	return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,b,c;string a;
    cin>>n>>m;
    int salaries[500005];
    cin>>salaries[1];
    for(int x=2;x<=n;x++){
    	cin>>salaries[x]>>parents[x];
    	adjlis[x].push_back(parents[x]);
    	adjlis[parents[x]].push_back(x);
    }
    parents[1]=-1;
    build(1);
    for(int x=0;x<m;x++){
    	cin>>a;
    	if(a=="p"){
    		cin>>b>>c;
    		update(preorder[b]+1,subtree[b],c);
    	}else{
    		cin>>b;
    		cout<<salaries[b]+query(preorder[b])<<'\n';
    	}
    }
    return 0;
}