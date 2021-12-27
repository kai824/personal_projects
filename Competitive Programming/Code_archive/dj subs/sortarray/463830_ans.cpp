// ans.cpp 25 Dec 18, 18:54:12 100 0.01 Judging completed in 2.019s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	char inc='=',nex;
	int n,ans=1;
	cin>>n;
	int arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	if(arr[0]==arr[1])inc='=';
	if(arr[0]<arr[1])inc='<';
	if(arr[0]>arr[1])inc='>';
	for(int x=2;x<n;x++){
		if(arr[x-1]==arr[x])nex='=';
		if(arr[x-1]<arr[x])nex='<';
		if(arr[x-1]>arr[x])nex='>';
		if(inc=='='){
			inc=nex;
		}else if(nex=='=')continue;
		else if((inc=='<' && nex=='>') || (nex=='<' && inc=='>')){
			ans++;
			inc='=';
		}
	}
	cout<<ans;
	return 0;
}