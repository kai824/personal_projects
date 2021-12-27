// ans.cpp 8 Dec 17, 20:04:48 64 0.19 Judging completed in 3.749s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll ft[1000005],n,mod=1e9+7;

ll ls(ll x){
	return(x&(-x));
}
ll update(ll p,ll v){
	for(;p<=n;p+=ls(p)){
	    ft[p]+=v;
	    ft[p]%=mod;
	}
}
ll query(ll p){
	ll sum=0;
	for(;p;p-=ls(p)){
	    sum+=ft[p];
	    sum%=mod;
	}
	return sum;
}
ll qquery(ll a,ll range){
	if(a+range<=n)return(query(a+range)-query(a-1));
	ll ans=query(n)-query(a-1);
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
ll multiply(ll a,ll b){
	ll ans=0,cur,c2=0;
	while(b>0){
		cur=b%10;
		cur*=a;
		cur%=mod;
		for(ll x=0;x<c2;x++){
			cur*=10;
			cur%=mod;
		}
		ans+=cur;
		ans%=mod;
		c2++;
		b/=10;
	}
	return ans;
}
main(){
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
    	ans=multiply(query(n),a);
    	ans%=mod;
    	ans+=qquery(X,(d%n));
    	ans%=mod;
    	update(X,Y);
    	cout<<ans<<'\n';
    }
    return 0;
}