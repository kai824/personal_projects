// ans.cpp 23 Dec 19, 21:37:37 100 0.04 Judging completed in 3.728s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ans[5005],c;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;cin>>s;
    ans[0]=1;//longest palindrome starting from 0...
    for(int x=1;x<s.length();x++){
        for(int y=0;y<x;y++){
            ans[y]=max(ans[y],ans[y+1]);
            if(s[y]==s[x]){
                ans[y]=max(ans[y],ans[y+1]+2);
            }
        }
		for(int y=x-1;y>=0;y--){
			ans[y]=max(ans[y],ans[y+1]);
		}
		ans[x]=1;
    }
    cout<<ans[0];
    return 0;
}