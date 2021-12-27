// ans.cpp 5 Dec 17, 14:17:13 30 0.01 Judging completed in 2.598s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long ft[200005],limit=200005;
long long ps[100005];
long long ls(long long x){
    return (x&(-x));
}
long long query(long long p){
    long long sum=0;
    for(;p;p-=ls(p)){
        sum+=ft[p];
    }
    return sum;
}
void update(long long p,long long v){
    for(;p<=limit;p+=ls(p)){
        ft[p]+=v;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,xx,cnt=0;
    cin>>n>>xx;
    long long ans=(n*(n+1))/2;
    long long arr[n+5];
    ps[0]=100000;
    for(long long x=1;x<=n;x++){
    	cin>>arr[x];
    	if(arr[x]>=xx)arr[x]=1;
    	else arr[x]=-1;
    	ps[x]=arr[x]+ps[x-1];
    }
    for(long long x=1;x<=n;x++){
        ans-=query(200000)-query(ps[x]);
        update(ps[x],1);
    }
    cout<<ans;
    return 0;
}