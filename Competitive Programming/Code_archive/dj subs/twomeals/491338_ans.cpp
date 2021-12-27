// ans.cpp 14 Feb 19, 20:44:23 100 0.11 Judging completed in 2.937s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[500005],fs[500005],bs[500005];//array, front sum, back sum
int main() {
    ll n,ans=0,cur=0;
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
    }
    fs[0]=0;
    for(int x=1;x<=n;x++){
        if(cur+arr[x]>0){
            cur+=arr[x];
			fs[x]=max(cur,fs[x-1]);
        }else{
			cur=0;
			fs[x]=fs[x-1];//since cur is positive
		}
    }
	cur=0;
    for(int x=n;x>=1;x--){
        if(cur+arr[x]>0){
            cur+=arr[x];
			bs[x]=max(cur,bs[x+1]);
        }else{
			cur=0;
			bs[x]=bs[x+1];
		}
    }
    for(int x=1;x<=n;x++){
        ans=max(ans,fs[x]+bs[x+1]);
    }
    cout<<ans;
    return 0;
}