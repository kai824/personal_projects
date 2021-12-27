// ans.cpp 5 Dec 17, 14:09:51 20 0 Judging completed in 3.697s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[200005],limit=200005;
int ps[100005];
int ls(int x){
    return (x&(-x));
}
int query(int p){
    int sum=0;
    for(;p;p-=ls(p)){
        sum+=ft[p];
    }
    return sum;
}
void update(int p,int v){
    for(;p<=limit;p+=ls(p)){
        ft[p]+=v;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,xx,cnt=0,ans=0;
    cin>>n>>xx;
    int arr[n+5];
    for(int x=1;x<=n;x++){
    	cin>>arr[x];
    	if(arr[x]>=xx)arr[x]=1;
    	else arr[x]=-1;
    	ps[x]=arr[x]+ps[x-1];
    }
    for(int x=1;x<=n;x++){
    	update(ps[x]+100000,1);
        ans+=query(ps[x]+100000);
    }cout<<ans;
    return 0;
}