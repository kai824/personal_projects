// ans.cpp 15 Mar 19, 11:42:29 100 0 Judging completed in 4.047s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
long long cnt[30];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string a;
	cin>>a;
	long long ans=(a.length()*(a.length()-1))/2+1;
	for(int x=0;x<a.length();x++){
		ans-=cnt[a[x]-'a'];
		cnt[a[x]-'a']++;
	}
	cout<<ans;
	return 0;
}