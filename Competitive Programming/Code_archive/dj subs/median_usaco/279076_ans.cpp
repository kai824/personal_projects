// ans.cpp 5 Dec 17, 14:15:31 20 0.02 Judging completed in 2.865s on AWS Oregon.
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
    int n,xx,cnt=0;
    cin>>n>>xx;
    long long ans=(n*(n+1))/2;
    int arr[n+5];
    ps[0]=100000;
    for(int x=1;x<=n;x++){
    	cin>>arr[x];
    	if(arr[x]>=xx)arr[x]=1;
    	else arr[x]=-1;
    	ps[x]=arr[x]+ps[x-1];
    }
    for(int x=1;x<=n;x++){
        ans-=query(200000)-query(ps[x]);
        update(ps[x],1);
    }
    cout<<ans;
    return 0;
}