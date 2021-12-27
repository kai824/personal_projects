// ans.cpp 21 Dec 19, 12:37:09 25 4 Judging completed in 8.229s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

#pragma O3
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,a,b,c,ans;
	cin>>n>>q;
	int arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	for(int x=0;x<q;x++){
		cin>>a>>b>>c;
		b--;
		if(a==1){
			arr[b]=c;
		}else{
			c--;
			ans=0;
			for(int i=b;i<=c;i++){
				a=arr[i];
				for(int j=i;j<=c;j++){
					a=__gcd(arr[j],a);
					if(a>1)ans++;
					else break;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}