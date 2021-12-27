// ans.cpp 23 Feb 19, 16:59:14 40 4 Judging completed in 13.326s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#pragma O3
int arr[200005],freq[100005],max_freq,ans,k,n,q,p,s;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	cin>>k>>n>>q;
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	
	for(int x=0;x<q;x++){
		cin>>p>>s;
		p--;//since p is 1-indexed...
		arr[p]=s;
		if(k==1){
		    if(n>5000){
		        //cout<<n<<'\n';continue;
		    }
			max_freq=0;ans=0;
			for(int x=0;x<n;x++){
				freq[arr[x]]++;
				max_freq=max(max_freq,freq[arr[x]]);
				if(max_freq*4>=3*(x+1)){
					ans=x+1;
				}
			}
			for(int x=0;x<n;x++){
				freq[arr[x]]--;
			}
			cout<<ans<<'\n';
		}else if(k==2){
			if(n>4000){
			    //cout<<n<<'\n';continue;
			}
			max_freq=0;ans=0;
			for(int x=0;x<n;x++){
				freq[arr[x]]++;
				max_freq=max(max_freq,freq[arr[x]]);
				if(max_freq*4>=3*(x+1)){
					ans++;
				}
				//cout<<max_freq<<' ';
			}
			for(int x=0;x<n;x++){
				freq[arr[x]]--;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
2 10 6
1 1 2 1 1 2 3 1 1 1
7 1
5 2
1 2
2 2
4 2
1 300
*  
1 10 6
1 1 2 1 1 2 3 1 1 1
7 1
5 2
1 2
2 2
4 2
1 300
* */