// ans.cpp 28 Nov 19, 10:33:38 18.18 1 Judging completed in 4.654s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool taken[1005];
int ps[1005][1005];
int n,m,s,a,b,cur;
inline int get_sum(int x1,int y1,int x2,int y2){
	if(x1<0)x1=0;
	if(y1<0)y1=0;
	if(x2>n)x2=n;
	if(y2>m)y2=m;
	return ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1];
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int lo,hi,mid,ans=0;
	cin>>n>>m>>s;
	if(s==0){
	    cout<<1;
	    return 0;
	}
	for(int x=0;x<1005;x++){
	    taken[x]=false;
	    for(int y=0;y<1005;y++){
	        ps[x][y]=0;
	    }
	}
	for(int x=0;x<s;x++){
		cin>>a>>b;
		ps[a][b]=1;
	}
	for(int x=1;x<=n;x++){
		cur=0;
		for(int y=1;y<=m;y++){
			cur+=ps[x][y];
			ps[x][y]=cur+ps[x-1][y];
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			lo=0;//current spot is a seed...
			hi=max(n,m);//max(max(x,y)-1,max(n-x,m-y));
			while(lo<hi){
				mid=lo+(hi-lo)/2;
				if(get_sum(x-mid,y-mid,x+mid,y+mid)>0){
					hi=mid;
				}else{
					lo=mid+1;
				}
			}
			if(get_sum(x-lo,y-lo,x+lo,y+lo)==0){
			    while(true){};
			}
			if(taken[lo]==false){
				taken[lo]=true;
				ans++;
			}
		}
	}
	cout<<ans;
	if(ans>8)while(true){}
	return 0;
}