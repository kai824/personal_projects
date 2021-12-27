// ans.cpp 23 Dec 19, 14:45:40 100 0.13 Judging completed in 3.772s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int arr[100005];
vector<int> adjl[100005];
bool vis[100005];
int dist[100005],preorder[100005],rt[100005],parent[100005];
int nex=1;

int dfs(int node){
	vis[node]=true;
	int cnt=1,a,cur=0,it=-1;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]==false){
			a=dfs(adjl[node][x]);
			cnt+=a;
			if(a>cur){
				cur=a;
				it=x;
			}
		}
	}
	if(it>0){
		swap(adjl[node][it],adjl[node][0]);
	}
	return cnt;
}
void dfs2(int node,int dd,int prev,int heavy_root=-1){
	if(heavy_root==-1)heavy_root=node;
	rt[node]=heavy_root;
	vis[node]=false;
	dist[node]=dd;parent[node]=prev;
	preorder[node]=nex;nex++;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]==true){
			if(x==0)dfs2(adjl[node][x],dd+1,node,heavy_root=heavy_root);//heavy edge...
			else dfs2(adjl[node][x],dd+1,node);//light edge...
		}
	}
}

int ft[100005];

inline int ls(int x){
    return x & (-x);
}

void update(int p,int v){
    for(;p<=100000;p+=ls(p))ft[p]^=v;
}

int query(int p){
    int ans=0;
    for(;p;p-=ls(p))ans^=ft[p];
    return ans;
}


int plant(int a,int b){
    int ans=0;
    if(dist[a]>dist[b])swap(a,b);
	while(rt[a]!=rt[b]){
		if(dist[rt[a]]>dist[rt[b]])swap(a,b);
		/*update(preorder[rt[b]],1);
		update(preorder[b]+1,-1);*/
        ans^=query(preorder[rt[b]]-1)^query(preorder[b]);
		b=parent[rt[b]];
	}
	if(dist[a]>dist[b])swap(a,b);
    ans^=query(preorder[a]-1)^query(preorder[b]);
	//update(preorder[a],1);update(preorder[b]+1,-1);
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,a,b,c;
    cin>>n>>q;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
    }
    for(int x=1;x<n;x++){
        cin>>a>>b;
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }
    dfs(1);//since nodes are 1-indexed...
    dfs2(1,1,1);
    for(int x=1;x<=n;x++){
        update(preorder[x],arr[x]);
    }
    for(int x=0;x<q;x++){
        cin>>a>>b>>c;
        if(a==1){
            update(preorder[b],arr[b]^c);
            arr[b]=c;
        }else{
            cout<<plant(b,c)<<'\n';
        }
    }
    return 0;
}