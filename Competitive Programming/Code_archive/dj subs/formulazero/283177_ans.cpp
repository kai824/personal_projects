// ans.cpp 8 Dec 17, 19:55:01 64 0.08 Judging completed in 3.97s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll ft[100005],n;

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
	int ans=query(n)-query(a-1);
	range-=(n-a);
	ans+=query(range);
	return ans;
}
ll calc(ll w,ll d){
	ll x=w-w%d,y,ans,z;//y is no. of elements*2
	y=x/d;
	if (w%d!=0){
		y++;
	}
	z=w%d;
	if (z==0)z=d;
	ans=(y*(z+w)/2);
	
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
    	d=calc(w,d);
    	a=d/n;//number of times he loops through the whole track...
    	ans=query(n)*a;
    	ans+=qquery(X,(d%n));
    	update(X,Y);
    	cout<<ans<<'\n';
    }
    return 0;
}