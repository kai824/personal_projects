// ans.cpp 18 Dec 19, 10:04:57 0 0.01 Judging completed in 3.592s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	int arr[n],cur,ans,ans2;
	cur=ans=ans2=0;
	bool positive=true;
	for(int x=0;x<n;x++){
		cin>>arr[x];
		cur+=arr[x];
		if(positive && arr[x]<=0){
			ans+=1-arr[x];
		}else if(positive==false && arr[x]>=0){
			ans+=arr[x]-1;
		}
		positive=!positive;
	}
	cur=0;
	positive=false;
	for(int x=0;x<n;x++){
		cur+=arr[x];
		if(positive && arr[x]<=0){
			ans2+=1-arr[x];
		}else if(positive==false && arr[x]>=0){
			ans2+=arr[x]-1;
		}
		positive=!positive;
	}
	cout<<min(ans,ans2);
	return 0;
}