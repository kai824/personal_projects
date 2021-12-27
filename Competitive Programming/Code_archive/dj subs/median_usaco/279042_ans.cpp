// ans.cpp 5 Dec 17, 13:11:13 0 0 Judging completed in 3.668s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,ans=0,cnt=0,a;
    cin>>n>>x;
    for(int x=0;x<n;x++){
    	cin>>a;
    	if(a>=x){
    		cnt++;
    	}else{
    		ans+=cnt;
    	}
    }
    long long ansans=(n*(n+1) )/2;
    cout<<ansans-ans;
    return 0;
}