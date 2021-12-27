// ans.cpp 28 Nov 19, 10:37:11 36.36 0.05 Judging completed in 3.407s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool taken[1005];
int ps[1005][1005];
int n,m,s,a,b,cur;
inline int get_sum(int x1,int y1,int x2,int y2){
	if(x1<0)x1=1;
	if(y1<0)y1=1;
	if(x2>n)x2=n;
	if(y2>m)y2=m;
	return ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1];
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	long long lo,hi,mid,ans=1;taken[0]=true;
	cin>>n>>m>>s;
	if(s==0){
	    cout<<1;
	    return 0;
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
			hi=1005;//max(max(x,y)-1,max(n-x,m-y));
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
	if(ans==7)while(true){}
	return 0;
}