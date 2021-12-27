// ans.cpp 10 May 18, 09:38:10 100 0.03 Judging completed in 3.334s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,d,last=-1,a,ans=0;
	cin>>n>>d;
	for(int x=0;x<n;x++){
		cin>>a;
		if(a==1){
			last=x;
		}else{
			if(x-last>=d){
				last=x;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}