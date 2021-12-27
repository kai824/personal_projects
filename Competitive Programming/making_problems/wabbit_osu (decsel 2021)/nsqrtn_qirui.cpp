#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll lim=1e7+5;
ll dp[lim],cnts[lim],x_pref[lim];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n;
	string s;
	cin>>n>>s;
	ll ctr=1;
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1])cnts[ctr-1]++,ctr=1;
		else ctr++;
	}
	cnts[ctr-1]++;
	ll mx=0;
	for(int i=1;i<=n;i++){
		if(cnts[i]>0){
			for(int j=1;j<=i;j++){
				ll k=i/j;
				x_pref[j]+=k*cnts[i];
	//			cout<<"j: "<<j<<" k:"<<k<<"\n";
				j=i/k;
				x_pref[j+1]-=k*cnts[i];
			}
			mx=max(mx,(ll)i);
		}
	}
	for(int i=1;i<=n;i++)x_pref[i]+=x_pref[i-1];//,cout<<i<<" "<<x_pref[i]<<"\n";
	ll pos=mx;
	x_pref[0]=1e18;
	for(int ctr=2;ctr<=2*n;ctr+=2){
		while(pos>=1&&x_pref[pos]<=ctr)pos--;
		cout<<pos+1<<" ";
	}
	return 0;
}