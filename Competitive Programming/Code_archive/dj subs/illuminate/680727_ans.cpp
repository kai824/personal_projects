// ans.cpp 18 Jan 20, 12:58:37 100 0.19 Judging completed in 5.272s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

string ss[2000005];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int r,c,cur;
	long long ans=0;
	cin>>r>>c;
	int l[r][c],rr[r][c],t[r][c],b[r][c];
	for(int x=0;x<r;x++){
		for(int y=0;y<c;y++){
			l[x][y]=rr[x][y]=t[x][y]=b[x][y]=-1;//number of empty stuff in a direction, before hitting sth... includes itself...
		}
	}
	for(int x=0;x<r;x++){
		cin>>ss[x];
		cur=-1;//last one...
		for(int y=0;y<c;y++){
			l[x][y]=y-cur;
			if(ss[x][y]=='#'){
				cur=y;
				l[x][y]=-1;
			}
		}
		cur=c;
		for(int y=c-1;y>=0;y--){
			rr[x][y]=cur-y;
			if(ss[x][y]=='#'){
				cur=y;
				rr[x][y]=-1;
			}
		}
	}
	for(int x=0;x<c;x++){
		cur=-1;
		for(int y=0;y<r;y++){
			t[y][x]=y-cur;
			if(ss[y][x]=='#'){
				cur=y;
				t[y][x]=-1;
			}
		}
		cur=r;
		for(int y=r-1;y>=0;y--){
			b[y][x]=cur-y;
			if(ss[y][x]=='#'){
				cur=y;
				b[y][x]=-1;
			}
		}
	}
	for(int x=0;x<r;x++){
		for(int y=0;y<c;y++){
			if(ss[x][y]=='#'){
				continue;
			}
			ans+=t[x][y]+b[x][y]+l[x][y]+rr[x][y];
			ans-=3;//cause don't include yourself 4 times, once is enough...
		}
	}
	cout<<ans;
	return 0;
}