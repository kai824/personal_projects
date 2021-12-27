// ans.cpp 2 Dec 19, 14:53:10 0 0.16 Judging completed in 4.723s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,cur,ans,total=0;
    cin>>n;
    long long arr[n],fs[n],bs[n];//front sum, back sum
    for(int x=0;x<n;x++){
        cin>>arr[x];
        total+=arr[x];
    }
    cur=0;
    for(int x=0;x<n;x++){
        cur+=arr[x];
        cur=max(cur,0ll);
        fs[x]=cur;
    }
    cur=0;
    for(int x=n-1;x>=0;x--){
        cur+=arr[x];
        cur=max(cur,0ll);
        bs[x]=cur;
        if(x>0)ans=max(ans,bs[x]+fs[x-1]);
        else ans=max(ans,bs[x]);
    }
    
    cur=0;
    for(int x=0;x<n;x++){
        cur+=arr[x];
        cur=min(cur,0ll);
        fs[x]=cur;
    }
    cur=0;
    for(int x=n-1;x>=0;x--){
        cur+=arr[x];
        cur=min(cur,0ll);
        bs[x]=cur;
        if(x>0)ans=max(ans,total-(bs[x]+fs[x-1]));
        else ans=max(ans,total-bs[x]);
    }
    return 0;
}