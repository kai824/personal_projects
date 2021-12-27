// ans.cpp 23 Feb 19, 14:36:25 34 0.23 Judging completed in 6.307s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,a,b,current,ans=0;
	cin>>n;
	ll bb[n+2],front_max[2+n],back_max[2+n];//represents the values...
	for(int x=1;x<=n;x++){
		cin>>bb[x];
	}
	vector<ll> adjmat[n+1];
	/*for(int x=1;x<n;x++){
		cin>>a>>b;
		adjmat[a].push_back(b);
		adjmat[b].push_back(a);
	}*/
	//assume line here...
	front_max[0]=0;back_max[n+1]=0;current=0;
	for(int x=1;x<=n;x++){
		current+=bb[x];
		if(current<0)current=0;
		front_max[x]=max(current,front_max[x-1]);//1d max sum
	}
	current=0;
	for(int x=n;x>0;x--){
		current+=bb[x];
		if(current<0)current=0;
		back_max[x]=max(current,back_max[x+1]);
	}
	for(int x=0;x<=n;x++){
		ans=max(front_max[x]+back_max[x+1],ans);
	}
	cout<<ans;
	return 0;
}