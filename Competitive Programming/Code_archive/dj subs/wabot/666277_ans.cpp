// ans.cpp 28 Dec 19, 13:32:17 7 0.15 Judging completed in 4.837s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bigg[1000005][3];//level, top 3...
int cnt[1000005];
ll sum[1000005];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,l,c;
	cin>>n;
	pair<ll,ll> arr[n];
	ll ans=0;
	for(int x=0;x<n;x++){
		cin>>arr[x].first>>arr[x].second;
		cnt[arr[x].first]++;
		sum[arr[x].first]+=arr[x].second;
		for(int i=0;i<3;i++){
			if(arr[x].second>=bigg[arr[x].first][i]){
				for(int j=i+1;j<3;j++){
					bigg[arr[x].first][j]=bigg[arr[x].first][j-1];
				}
				bigg[arr[x].first][i]=arr[x].second;
				break;
			}
		}
	}
	for(int x=1;x<=10;x++){
		cnt[x+1]+=cnt[x]/2;
		if(cnt[x]==1)continue;
		if(cnt[x]%2==0){
			//even...
			sum[x+1]+=sum[x];
			ans+=sum[x];
			c=bigg[x][0]+bigg[x][1];
			for(int i=0;i<3;i++){
				if(c>=bigg[x+1][i]){
					for(int j=i+1;j<3;j++){
						bigg[x+1][j]=bigg[x+1][j-1];
					}
					bigg[x+1][i]=c;
					break;
				}
			}
		}else{
			sum[x+1]+=sum[x]-bigg[x][0];
			ans+=sum[x]-bigg[x][0];
			c=bigg[x][1]+bigg[x][2];
			for(int i=0;i<3;i++){
				if(c>=bigg[x+1][i]){
					for(int j=i+1;j<3;j++){
						bigg[x+1][j]=bigg[x+1][j-1];
					}
					bigg[x+1][i]=c;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*

*/