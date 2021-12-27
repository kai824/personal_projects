// ans.cpp 22 Nov 19, 14:32:49 100 0.33 Judging completed in 5.455s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;


int dp[2][5005];
int arr[5005],arr2[5005];//forward, backward...
bool broke,bit=1;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,c,cur_start=0,ans=1e9,cur;
    cin>>n>>c;
    string mp[c];
    for(int x=0;x<c;x++){
        cin>>mp[x];
		if(mp[x][0]=='1')dp[0][x]=0;
		else dp[0][x]=1e9;
    }
	for(int x=1;x<n;x++){
		cur=1e9;
		for(int i=0;i<c;i++){//forward
			arr[i]=cur=min(cur,dp[!bit][i]+n-i);
			//cout<<arr[i]<<' ';
		}//cout<<"\n\n";
		cur=1e9;
		for(int i=c-1;i>=0;i--){
			arr2[i]=cur=min(cur,dp[!bit][i]+i);
			//cout<<arr2[i]<<' ';
		}//cout<<"\n\n";
		for(int i=0;i<c;i++){
			dp[bit][i]=1e9;
			if(mp[i][x]=='1')dp[bit][i]=min(arr[i]-(n-i),arr2[i]-i);
			//cout<<dp[bit][i]<<' ';
			if(x==n-1){
				ans=min(ans,dp[bit][i]);
			}
		}//cout<<"\n\n";
		bit=!bit;
	}
	cout<<ans;
    return 0;
}