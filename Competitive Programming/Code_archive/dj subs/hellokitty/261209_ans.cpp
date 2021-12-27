// ans.cpp 18 Nov 17, 15:27:33 31 0.2 Judging completed in 6.993s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,lo,hi,mid,ans;
int x[100005],y[100005];
int ps_x[100005],ps_y[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<pair<int,int>,bool> mp;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		mp.insert(make_pair(make_pair(x[i],y[i]),true));
	}
	sort(x+1,x+n+1);sort(y+1,y+n+1);
	for(int i=1;i<=n;i++){
		ps_x[i]=ps_x[i-1]+x[i];
		ps_y[i]=ps_y[i-1]+y[i];
		//prefix sum them...
	}
	cin>>m;
	for(int i=0;i<m;i++){
		//queries
		//NOT COMPLETED HERE...
		cin>>a>>b;
		if(mp[make_pair(a,b)]==true){
			cout<<"Cannot build here.\n";
			continue;
		}
		
		ans=0;
		
		//find a in array x...
		lo=1;hi=n;
		while(lo<hi){
			mid=(lo+hi)/2;
			if(x[mid]<a){
				lo=mid+1;
			}else{
				hi=mid;
			}
		}if(a<x[lo])lo--;
		ans+=ps_x[n]-ps_x[lo];
		ans-=a*(n-lo);
		ans+=a*(lo);
		ans-=ps_x[lo];
		//find b in array y...
		lo=1;hi=n;
		while(lo<hi){
			mid=(lo+hi)/2;
			if(y[mid]<b){
				lo=mid+1;
			}else{
				hi=mid;
			}
		}if(b<y[lo])lo--;
		ans+=ps_y[n]-ps_y[lo];
		ans-=b*(n-lo);
		
		ans+=b*(lo);
		ans-=ps_y[lo];
		
		cout<<ans<<'\n';
	}
    return 0;
}