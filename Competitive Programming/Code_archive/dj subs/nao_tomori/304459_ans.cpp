// ans.cpp 24 Dec 17, 19:50:08 100 0.51 Judging completed in 3.817s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[1000005],n;
bool f[1000005];
int ls(int x){
	return(x&(-x));
}
void update(int p,int v){
	for(;p<=n;p+=ls(p)){
		ft[p]+=v;
	}
}
int query(int p){
	int sum=0;
	for(;p;p-=ls(p)){
		sum+=ft[p];
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m,a,lo,hi,mid,cursize;
	cin>>n>>m;cursize=n;
	for(int x=0;x<n;x++){
		update(x+1,1);
	}
	for(int x=0;x<m;x++){
		cin>>a;
		a--;
		a%=cursize;
		a++;
		lo=1;hi=n;
		while(lo<hi){
			mid=(lo+hi)/2;
			if(query(mid)>=a){//big enough
				hi=mid;
			}else{//too small
				lo=mid+1;
			}
		}
		update(lo,-1);
		lo--;
		f[lo]=true;
		cursize--;
	}
	bool first=true;
	for(int x=0;x<n;x++){
		if(f[x]==false){
			if(first==false){
				cout<<' ';
			}else first=false;
			cout<<x;
		}
	}
	return 0;
}