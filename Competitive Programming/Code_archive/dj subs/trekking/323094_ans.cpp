// ans.cpp 8 Feb 18, 09:27:41 23 0.04 Judging completed in 6.049s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//trekking floyd warshall...
ll adjmats[15][105][105];
string as[15]={"0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};//stores whether something is relevant in adjmat[x]...
ll costs[15];
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,q;
	cin>>n>>m>>q;
	ll t[4];
	for(ll x=0;x<4;x++)cin>>t[x];
	for(ll x=0;x<15;x++){
		for(ll y=0;y<4;y++){
			if(as[x][y]=='1'){
				costs[x]+=t[y];
			}
		}
		for(ll y=0;y<105;y++){
			for(ll z=0;z<105;z++){
				adjmats[x][y][z]=-1;
				if(y==z)adjmats[x][y][z]=0;
			}
		}
	}
	ll u,v,c,d,ans;string in;
	map<string,ll>mp;
	mp["ground"]=0;
	mp["water"]=1;
	mp["grass"]=2;
	mp["forest"]=3;
	for(ll x=0;x<m;x++){
		cin>>u>>v>>c>>in;
		d=mp[in];
		for(ll y=0;y<15;y++){
			if(as[y][d]=='0')continue;
			adjmats[y][u][v]=c;
			adjmats[y][v][u]=c;
		}
	}
	
	for(ll i=0;i<15;i++){
		for(ll x=1;x<=n;x++){
			for(ll y=1;y<=n;y++){
				for(ll z=1;z<=n;z++){
					if(adjmats[i][y][x]==-1)continue;
					if(adjmats[i][x][z]==-1)continue;
					//the fact that it's still running means that the 2 edges^ are legit
					if(adjmats[i][y][z]==-1){
						adjmats[i][y][z]=adjmats[i][y][x]+adjmats[i][x][z];
						continue;
					}
					adjmats[i][y][z]=min(adjmats[i][y][z],adjmats[i][y][x]+adjmats[i][x][z]);
				}
			}
		}
	}
	
	for(ll x=0;x<q;x++){
		cin>>u>>v;
		ans=-1;
		for(ll y=0;y<15;y++){
			if(adjmats[y][u][v]==-1){
				continue;
			}
			if(ans==-1){
				ans=adjmats[y][u][v]+costs[y];
				continue;
			}
			ans=min(ans,adjmats[y][u][v]+costs[y]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}