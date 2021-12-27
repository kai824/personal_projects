// ans.cpp 28 Nov 19, 22:31:12 30 2.37 Judging completed in 7.031s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

string mp[2005];
set<int> vs[2005],hs[2005];
char vis[2005][2005];
int ans=0;

void dfs(int x,int y){
	vis[x][y]='p';//processing...
	set<int>::iterator it;
	set<int> *ptr;
	int dx,dy,nx,ny;
	if(mp[x][y]=='N')dx=-1,dy=0;
	else if(mp[x][y]=='S')dx=1,dy=0;
	else if(mp[x][y]=='E')dx=0,dy=1;
	else if(mp[x][y]=='W')dx=0,dy=-1;
	if(dx==0)ptr=&hs[x],it=hs[x].find(y);
	else ptr=&vs[y],it=vs[y].find(x);
	while(true){
		if(dx+dy<0){
			if(it==ptr->begin())break;
			it--;
		}else{
			it++;
			if(it==ptr->end())break;
		}
		if(dx==0)nx=x,ny=*it;
		else ny=y,nx=*it;
		if(vis[nx][ny]=='p'||vis[nx][ny]=='#'){
			vis[x][y]='#';
			return;
		}else{
			if(vis[nx][ny]=='n'){
				dfs(nx,ny);
				if(vis[nx][ny]=='#'){
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
    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>mp[x];
		for(int y=0;y<m;y++){
			vis[x][y]='n';//completely new...
			if(mp[x][y]!='.'){
				hs[x].insert(y);
				vs[y].insert(x);
			}
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