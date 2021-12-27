// ans.cpp 25 Oct 19, 23:30:07 0 1.22 Judging completed in 5.683s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,preorder[1000005],a,b,parents[1000005],nex=1;
bool visited[1000005];

vector<int> adjlis[1000005];
int subtree[1000005];

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
    int salaries[1000005];
    for(int x=0;x<n;x++){
    	cin>>parents[x];
    	adjlis[x].push_back(parents[x]);
    	adjlis[parents[x]].push_back(x);
    }
    for(int x=0;x<n;x++){
        cin>>salaries[x];
    }
    parents[0]=-1;
    build(0);
    for(int x=0;x<m;x++){
    	cin>>a;
    	if(a=="0"){
    		cin>>b>>c;
    		update(preorder[b],subtree[b],c);
    	}else{
    		cin>>b;
    		cout<<salaries[b]+query(preorder[b])<<'\n';
    	}
    }
    return 0;
}