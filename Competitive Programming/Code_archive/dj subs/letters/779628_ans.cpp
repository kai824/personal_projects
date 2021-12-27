// ans.cpp 9 Nov 20, 14:10:58 0 0 Judging completed in 5.549s on AWS Oregon.
#include<bits/stdc++.h> 
using namespace std;
#define int long long

int dp[1000005][27];
main(){ 
	long long n;
	string s;
	cin>>s;
	
	n=s.length();
    string cmp="abcdefghijklmnopqrstuvwxyz";
    
    
    for(int i=0;i<=26;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=26;j++){
			if(s[i-1]==cmp[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j]; 
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][26];
}