// ans.cpp 8 Dec 17, 19:05:24 0 0.1 Judging completed in 3.981s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ft[100000],n;

ll ls(ll x){
	return(x&(-x));
}
ll update(ll p,ll v){
	for(;p<=n;p+=ls(p))ft[p]+=v;
}
ll query(ll p){
	ll sum=0;
	for(;p;p-=ls(p))sum+=ft[p];
	return sum;
}
ll qquery(ll a,ll range){
	if(a+range<=n)return(query(a+range)-query(a-1));
	ll ans=query(n)-query(a-1);
	range-=(n-a);
	ans+=query(range);
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r,X,w,d,Y,N,a,ans;
    cin>>r>>n;
    for(ll x=1;x<=n;x++){
    	cin>>a;
    	update(x,a);
    }
    for(ll x=0;x<r;x++){
    	cin>>X>>w>>d>>Y;
    	//calculating actual distance as d...
    	N=w/d;
    	if(w%d==0){
    		d=(w*N-((N*(N+1)*d)/2))+w;
    	}else d=w*N-((N*(N+1)*d)/2);
    	d++;
    	a=d/n;//number of times he loops through the whole track...
    	ans=query(n)*a;
    	ans+=qquery(X,(d%n)-1);
    	update(X,Y);
    	cout<<ans<<'\n';
    }
    return 0;
}