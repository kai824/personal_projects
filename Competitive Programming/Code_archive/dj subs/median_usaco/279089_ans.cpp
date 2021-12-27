// ans.cpp 5 Dec 17, 14:29:02 30 0.01 Judging completed in 3.5s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int ft[200005],limit=200004;
int ls(int x){
    return (x&(-x));
}
int query(int p){
    p+=100000;
    int sum=0;
    for(;p;p-=ls(p)){
        sum+=ft[p];
    }
    return sum+1;
}
void update(int p,int v){
    p+=100000;
    for(;p<=limit;p+=ls(p)){
        ft[p]+=v;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,xx,s=0;
    cin>>n>>xx;
    long long ans=0;
    int arr[n+5];
    for(int x=1;x<=n;x++){
    	cin>>arr[x];
    	if(arr[x]>=xx)arr[x]=1;
    	else arr[x]=-1;
    }
    for(int x=1;x<=n;x++){
        s+=arr[x];
        ans+=query(s);
        update(s,1);
    }
    cout<<ans;
    return 0;
}