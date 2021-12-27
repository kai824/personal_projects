// ans.cpp 28 Nov 19, 22:52:27 60 2.05 Judging completed in 6.339s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
string mp[2005];
//set<int> vs[2005],hs[2005];
short int pv[2005][2005],ph[2005][2005],nv[2005][2005],nh[2005][2005];
char vis[2005][2005];
int ans=0;

void dfs(int x,int y){
	vis[x][y]='p';//processing...
	short int cx=x,cy=y;
	while(true){
		if(mp[x][y]=='N')cx=pv[cx][cy];
		else if(mp[x][y]=='S')cx=nv[cx][cy];
		else if(mp[x][y]=='E')cy=nh[cx][cy];
		else if(mp[x][y]=='W')cy=ph[cx][cy];
		if(min(cx,cy)==-1)break;
		if(vis[cx][cy]=='p'||vis[cx][cy]=='#'){
			vis[x][y]='#';
			return;
		}else{
			if(vis[cx][cy]=='n'){
				dfs(cx,cy);
				if(vis[cx][cy]=='#'){
					vis[x][y]='#';
					return;
				}
			}
		}
	}
	vis[x][y]='Y';//can leave...
	ans++;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,last;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>mp[x];
		for(int y=0;y<m;y++){
			vis[x][y]='n';//completely new...
			/*if(mp[x][y]!='.'){
				hs[x].insert(y);
				vs[y].insert(x);
			}*/
		}
    }
	for(int x=0;x<n;x++){
		last=-1;
		for(int y=0;y<m;y++){
			ph[x][y]=last;
			if(mp[x][y]!='.')last=y;
		}
		last=-1;
		for(int y=m-1;y>=0;y--){
			nh[x][y]=last;
			if(mp[x][y]!='.')last=y;
		}
	}
	for(int x=0;x<m;x++){
		last=-1;
		for(int y=0;y<n;y++){
			pv[y][x]=last;
			if(mp[y][x]!='.')last=y;
		}
		last=-1;
		for(int y=n-1;y>=0;y--){
			nv[y][x]=last;
			if(mp[y][x]!='.')last=y;
		}
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(mp[x][y]=='.')continue;
			if(vis[x][y]!='n')continue;
			dfs(x,y);
		}
	}
	cout<<ans;
    return 0;
}