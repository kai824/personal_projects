// ans.cpp 24 Dec 19, 10:50:31 100 0.91 Judging completed in 5.721s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int prevv[500005],depth[500005];//as in no. of edges...
char dist[500005];
vector<pair<int,char> > adjl[500005];
bool neww[500005];

char rec(int a,int b){//should ensure same depth first...
	if(a==b)return '=';
	char ans=rec(prevv[a],prevv[b]);
	if(ans!='=')return ans;
	if(dist[a]<dist[b])return '<';
	else if(dist[a]>dist[b])return '>';
	else return '=';
}

bool cmp(pii a,pii b){//pair of number of edges, and node...
	if(a.first==b.first){
		char c=rec(a.second,b.second);
		if(c=='=')return a.first>b.first;
		if(c=='>')return true;
		return false;
	}
	return a.first>b.first;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,s,t,a,b,c;
	char d;
	cin>>n>>m>>s>>t;
	if(s==t){
		cout<<0;return 0;
	}
	for(int x=0;x<=n;x++){
		prevv[x]=-1;
		depth[x]=1e9;
		dist[x]='-';
		neww[x]=false;
	}
	for(int x=0;x<m;x++){
		cin>>a>>b>>c;
		adjl[a].emplace_back(b,c+'0');
		adjl[b].emplace_back(a,c+'0');
	}
	priority_queue<pii,vector<pii>, greater<pii> > dijk;
	//distance(number of edges), node...
	prevv[s]=-1;dist[s]='0';//weight of last edge...
	depth[s]=0;neww[s]=true;
	dijk.push(make_pair(0,s));
	while(!dijk.empty()){
		a=dijk.top().second;
		if(dijk.top().first>depth[a]){//outdated...
			dijk.pop();continue;
		}
		dijk.pop();
		if(neww[a]==false)continue;
		for(int x=0;x<adjl[a].size();x++){
			b=adjl[a][x].first;
			if(depth[a]+1<depth[b]){
				depth[b]=depth[a]+1;
				dist[b]=adjl[a][x].second;
				prevv[b]=a;
				dijk.push(make_pair(depth[b],b));
				neww[b]=true;
			}else if(depth[a]+1==depth[b]){
				d=rec(a,prevv[b]);
				if(d=='<' || (d=='=' && adjl[a][x].second<dist[b]) ){
					dist[b]=adjl[a][x].second;
					prevv[b]=a;
					dijk.push(make_pair(depth[b],b));
					neww[b]=true;
				}
			}
		}
		neww[a]=false;
	}
	if(prevv[t]==-1){
		cout<<-1;return 0;
	}
	vector<char> v;
	while(t!=s){
		v.push_back(dist[t]);
		t=prevv[t];
	}
	while(v.size()>0){
		cout<<v.back();
		v.pop_back();
	}
	return 0;
}
/*
6 6 0 5
0 1 1
1 2 9
2 5 3
0 3 1
3 4 4
4 5 9
*/