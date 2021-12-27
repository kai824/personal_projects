// ans.cpp 25 May 19, 17:35:11 100 0.03 Judging completed in 3.337s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,s=0;
    long long ans=0;
    cin>>n>>m;
    mp[0]=1;
    for(int x=0;x<n;x++){
        cin>>a;
        s+=a;s%=m;
        if(mp.find(s)!=mp.end()){
            ans+=mp[s];
            mp[s]++;
        }
        else{
            mp[s]=1;
        }
    }
    cout<<ans;
    return 0;
}