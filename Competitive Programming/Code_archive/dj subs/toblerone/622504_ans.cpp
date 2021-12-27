// ans.cpp 2 Dec 19, 15:05:43 70 0.19 Judging completed in 5.264s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,cur,ans=0,total=0;
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
        if(x>0)fs[x]=max(cur,fs[x-1]);
		else fs[x]=cur;
		ans=max(ans,fs[x]);
    }
    cur=0;
    for(int x=n-1;x>=0;x--){
        cur+=arr[x];
        cur=max(cur,0ll);
		if(x==n-1)bs[x]=cur;
		else bs[x]=max(bs[x+1],cur);
        if(x>0)ans=max(ans,bs[x]+fs[x-1]);
        else ans=max(ans,bs[x]);
    }
    
    cur=0;
    for(int x=0;x<n;x++){
        cur+=arr[x];
        cur=min(cur,0ll);
        if(x>0)fs[x]=min(cur,fs[x-1]);
		else fs[x]=cur;
		ans=max(ans,fs[x]);
    }
    cur=0;
    for(int x=n-1;x>=0;x--){
        cur+=arr[x];
        cur=min(cur,0ll);
        if(x==n-1)bs[x]=cur;
		else bs[x]=min(bs[x+1],cur);
        if(x>0)ans=max(ans,total-(bs[x]+fs[x-1]));
        else ans=max(ans,total-bs[x]);
    }
	cout<<ans;
    return 0;
}