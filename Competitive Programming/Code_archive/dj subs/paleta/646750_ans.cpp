// ans.cpp 14 Dec 19, 12:50:40 5 1.1 Judging completed in 4.993s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static ll mod=1e9+7;
ll ans=1;
ll n,k,a;

bool vis[1000005];
int arr[1000005],pos[1000005];
vector<int> adjl[1000005];
bool weird=false;

void dfs(int node){
	vis[node]=true;
	int cnt=0,mini=INT_MAX,prev;
	bool exception=false;;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]){
			cnt++;
			if(pos[adjl[node][x]]>0)mini=min(mini,pos[adjl[node][x]]);
			if(cnt>=2){
				if(arr[prev]==adjl[node][x] || arr[adjl[node][x]]==prev){
					exception=true;//distance between both is just 1
				}
			}
			prev=adjl[node][x];
		}
	}
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]){
			continue;
		}
		dfs(adjl[node][x]);
	}
	if(k-cnt<=0)weird=true;
	if(cnt>=2 && exception==false){
	    if(mini==1)weird=true;
		ans=(ans*(k-cnt)) + (ans*(mini-1)/mini);
	}else ans*=(k-cnt);
	pos[node]=k-cnt;
	ans%=mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	for(int x=1;x<=n;x++){
		cin>>a;
		arr[x]=a;
		adjl[a].push_back(x);
		adjl[x].push_back(a);
	}
	for(int x=1;x<=n;x++){
		sort(adjl[x].begin(),adjl[x].end());
		a=unique(adjl[x].begin(),adjl[x].end())-adjl[x].begin();
		while(adjl[x].size()>a){
			adjl[x].pop_back();
		}
	}
	dfs(1);
	if(weird)cout<<0;
	else cout<<ans;
	return 0;
}