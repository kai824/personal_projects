// ans.cpp 22 Jul 20, 18:09:21 100 0.15 Judging completed in 4.972s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

bool vis[200005];
vector<int> adjl[200005];
int  depth[200005],ans=1,root,d=1;

int dfs(int node,int prev,int d=1){//returns the shallowest backedge...
  vis[node]=true;
	depth[node]=d;
  int shal=d,cnt=0,t;//shallowest back edge
  if(prev!=-1)cnt=1;//above section is 1...
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    if(vis[adjl[node][i]]){
      shal=min(shal,depth[adjl[node][i]]);
      continue;
    }
    t=dfs(adjl[node][i],node,d+1);
    if(t>=d)cnt++;
    shal=min(shal,t);
  }
  ans=max(ans,cnt);
  return shal;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,e,a,b;
	cin>>n>>e;
	for(int x=0;x<e;x++){
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	root=0;
	dfs(root,-1);
	cout<<ans;
	return 0;
}