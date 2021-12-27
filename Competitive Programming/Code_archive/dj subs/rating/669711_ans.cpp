// ans.cpp 31 Dec 19, 17:20:04 0 1.13 Judging completed in 7.337s on AWS Oregon.
/*inline void read(long long &x) {
    x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch & 15);
		ch = getchar_unlocked();
	}
}*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ps[4000005];
ll ans[4000005];
ll sum1,sum2;
/*sum of the squares...
front the front, and the back*/

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,i;
	cin>>n;
	pair<int,int> arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x].first;
		arr[x].second=x+1;
	}
	sort(arr,arr+n);
	for(int x=0;x<n;x++){
		ps[x+1]=ps[x]+arr[x].first;
		sum2+=arr[x].first*arr[x].first;
	}
	for(int x=0;x<n;x++){
		sum2-=arr[x].first*arr[x].first;
		i=arr[x].second;
		ans[i]+=arr[x].first*arr[x].first*x;
		ans[i]+=sum1;
		ans[i]-=2*arr[x].first*ps[x];

		ans[i]-=arr[x].first*arr[x].first*(n-1-x);
		ans[i]-=sum2;
		ans[i]+=2*arr[x].first*(ps[n]-ps[x+1]);
		sum1+=arr[x].first*arr[x].first;
	}
	for(int x=1;x<=n;x++){
		cout<<ans[x];
		if(x<n)cout<<' ';
	}
	return 0;
}