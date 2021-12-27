// ans.cpp 23 Dec 19, 21:20:28 100 0 Judging completed in 3.11s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,m,sum=0,ans,cur=0;
	cin>>n>>m;
	int arr[n];
	for(int x=0;x<n;x++){
		arr[x]=m;
		sum+=m;
	}
	sum/=m;//m tasters of n sausages...
	ans=m;
	for(int x=0;x<n;x++){
		cur+=arr[x];cur%=sum;
		if(cur==0)ans--;
	}
	cout<<ans;
	return 0;
}