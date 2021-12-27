// ans.cpp 10 Dec 17, 19:46:29 0 0.04 Judging completed in 6.465s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
//trekking floyd warshall...
int adjmats[15][105][105];
string as[15]={"0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};//stores whether something is relevant in adjmat[x]...
int costs[15];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,q;
	cin>>n>>m>>q;
	int t[4];
	for(int x=0;x<4;x++)cin>>t[x];
	for(int x=0;x<15;x++){
		for(int y=0;y<4;y++){
			if(as[x][y]=='1'){
				costs[x]+=t[y];
			}
		}
		for(int y=0;y<105;y++){
			for(int z=0;z<105;z++){
				adjmats[x][y][z]=-1;
			}
		}
	}
	int u,v,c,d,ans;string in;
	map<string,int>mp;
	mp["ground"]=0;
	mp["water"]=1;
	mp["grass"]=2;
	mp["forest"]=3;
	for(int x=0;x<m;x++){
		cin>>u>>v>>c>>in;
		d=mp[in];
		for(int y=0;y<15;y++){
			if(as[y][d]=='0')continue;
			adjmats[y][u][v]=c;
			adjmats[y][v][u]=c;
		}
	}
	
	for(int i=0;i<15;i++){
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				for(int z=1;z<=n;z++){
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
	
	for(int x=0;x<q;x++){
		cin>>u>>v;
		ans=-1;
		for(int y=0;y<15;y++){
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