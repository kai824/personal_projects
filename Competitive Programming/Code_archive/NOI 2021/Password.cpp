#include<bits/stdc++.h>
using namespace std;

#define int long long

int arr[300005];
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,ans=0;
	cin>>n>>m;m++;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		arr[i]=(a-arr[i]+m)%m;
		if(arr[i]>arr[i-1])ans+=arr[i]-arr[i-1];
	}
	priority_queue<int> pq;
	for(int i=1;i<=n;i++){
		if(arr[i]==arr[i-1])continue;
		if(arr[i]>arr[i-1]){
			//y
			if(pq.empty())continue;//too bad
			a=m-(arr[i]-arr[i-1])-pq.top();
			if(a<0){
				//worth adding m to whole range
				ans+=a;
				pq.pop();
				pq.push(m-(arr[i]-arr[i-1]) );
			}else{
				continue;
			}
		}else{
			//x
			pq.push(arr[i-1]-arr[i]);
		}
	}
	cout<<ans;
}
