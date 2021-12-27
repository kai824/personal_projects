// ans.cpp 1 Feb 20, 09:25:56 0 0.01 Judging completed in 5.09s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int arr[3005],ps[3005],cur_max;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>arr[x];
		ps[x]=ps[x-1]+arr[x];
	}
	for(int x=1;x<=n;x++){
		cur_max=arr[x];
		for(int y=x+1;y<=n;y++){
			cur_max=max(cur_max,arr[y]);
			if((ps[y]-ps[x-1]-cur_max)%m==0)ans++;
		}
	}
	cout<<ans;
	return 0;
}