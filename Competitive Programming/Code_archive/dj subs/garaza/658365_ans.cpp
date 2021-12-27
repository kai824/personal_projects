// ans.cpp 21 Dec 19, 12:57:54 0 4 Judging completed in 8.314s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

#pragma O3
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,a,b,c,ans;
	cin>>n>>q;
	int arr[n],val[n];
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	for(int x=0;x<n;x++){
	    a=arr[x];
	    if(a==1){
	        val[x]=x;
	    }
	    for(int y=x;y<=n;y++){
	        if(a==1 || y==n){
	            val[x]=y;
	            break;
	        }
	        a=__gcd(arr[y],a);
	    }
	    //update();
	}
	for(int x=0;x<q;x++){
		cin>>a>>b>>c;
		b--;
		if(a==1){
			arr[b]=c;
			for(int i=0;i<b;i++){
			    a=arr[i];
			    for(int j=i;j<=n;j++){
			        if(a==1 || j==n){
			            val[i]=j;
			            break;
			        }
			        a=__gcd(a,arr[j]);
			    }
			}
		}else{
			c--;
			ans=0;
			for(int i=b;i<=c;i++){
				ans+=min(val[i],c+1)-i;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}