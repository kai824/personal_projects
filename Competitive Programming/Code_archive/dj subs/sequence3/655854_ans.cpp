// ans.cpp 19 Dec 19, 10:39:30 100 0.01 Judging completed in 4.114s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	long long arr[n],cur,ans,ans2;
	cur=ans=ans2=0;
	bool positive=true;
	for(int x=0;x<n;x++){
		cin>>arr[x];
		cur+=arr[x];
		if(positive && cur<=0){
			ans+=1-cur;
			cur=1;
		}else if(positive==false && cur>=0){
			ans+=cur+1;
			cur=-1;
		}
		positive=!positive;
	}
	cur=0;
	positive=false;
	for(int x=0;x<n;x++){
		cur+=arr[x];
		if(positive && cur<=0){
			ans2+=1-cur;
			cur=1;
		}else if(positive==false && cur>=0){
			ans2+=cur+1;
			cur=-1;
		}
		positive=!positive;
	}
	//cout<<ans<<' '<<ans2;
	cout<<min(ans,ans2);
	return 0;
}