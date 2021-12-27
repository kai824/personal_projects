// ans.cpp 21 Oct 17, 11:58:09 26 0.13 Judging completed in 4.671s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ans[1000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,start;
    char direction;
    cin>>n>>k;
    
    for(int x=1;x<k;x++){
    	cout<<x<<' ';
    }
    cout<<k<<'\n';
    
    if(k%2==0){
    	start=k/2;
    	start++;
    	direction='d';
    }else{
    	direction='u';
    	start=(k+1)/2;
    }
    for(int x=1;x<=k;x++){
    	ans[start]=x;
    	if(direction=='d'){
    		start-=x;
    	}else{
    		start+=x;
    	}
    }
    for(int x=k+1;x<=n;x++){
    	ans[x]=x;
    }
    for(int x=1;x<n;x++){
    	cout<<ans[x]<<' ';
    }
    cout<<ans[n];
    return 0;
}