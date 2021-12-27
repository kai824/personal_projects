// ans.cpp 9 Dec 17, 11:59:14 100 0.55 Judging completed in 4.176s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int n,parent[20][500005],a,b,parents[500005];
bool visited[500005];

vector<int> adjlis[500005];

void build(int x){//visits parents before children...
    visited[x]=true;
    
    for(int i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            parents[adjlis[x][i] ]=x;
            parent[0][adjlis[x][i]]=x;
            build(adjlis[x][i]);
        }
    }
}

void init(int node){
	for(int i=1;i<20;i++){
		for(int j=0;j<n;j++){
			if(parent[i-1][j]==-1){
				parent[i][j]=-1;
				continue;
			}
			parent[i][j]=parent[i-1][parent[i-1][j]];
		}
	}
}

int query(int x,int k,int next_bit){
	if(x==-1)return -1;
	if(k==0)return x;
	if(k<(1<<next_bit)){//next_bit too huge...
		return query(x,k,next_bit-1);
	}
	//k>=1<<nextbit, so parent[x][next_bit] is relevant...
	return query(parent[next_bit][x],k-(1<<next_bit),next_bit-1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int x=1;x<n;x++){
        cin>>a>>b;
        adjlis[b].push_back(a);
        adjlis[a].push_back(b);
    }
    parents[0]=-1;
    parent[0][0]=-1;
    build(0);
    init(0);
    int q;
    cin>>q;
    for(int x=0;x<q;x++){
    	cin>>a>>b;
    	cout<<query(a,b,19)<<'\n';
    }
    return 0;
}