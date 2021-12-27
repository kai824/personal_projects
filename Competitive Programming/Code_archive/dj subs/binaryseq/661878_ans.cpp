// ans.cpp 23 Dec 19, 21:20:37 100 0.03 Judging completed in 3.759s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ppow[2000005];//powers of 3...

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string m;
	cin>>m;
	ll cur=0,prev=1;
	ppow[0]=1;
	for(int x=1;x<m.length();x++){
		ppow[x]=ppow[x-1]*3;
		ppow[x]%=1000000007;
	}
	for(int x=0;x<m.length();x++){
		if(m[x]=='1'){
			cur+=ppow[m.length()-x-1]*prev;
			//cout<<ppow[m.length()-x-1]<<' '<<prev<<'\n';
			prev*=2;
			prev%=1000000007;
		}
		cur%=1000000007;
	}
	cout<<cur;
	return 0;
}
//1001001111110011110001010011