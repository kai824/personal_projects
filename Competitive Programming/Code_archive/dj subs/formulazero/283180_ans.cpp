// ans.cpp 8 Dec 17, 19:58:13 0 0 Compilation failed on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef unsigned long long ll;
ll ft[100005],n;

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
ll multiply(ll a,ll b){
	ll ans=0,cur,c2=0;
	while(b>0){
		cur=b%10;
		cur*=a;
		cur%=m;
		for(int x=0;x<c2;x++){
			cur*=10;
			cur%=m;
		}
		ans+=cur;
		ans%=m;
		c2++;
		b/=10;
	}
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
    	ans=multiply(query(n),a);
    	ans%=mod;
    	ans+=qquery(X,(d%n));
    	ans%=mod;
    	update(X,Y);
    	cout<<ans<<'\n';
    }
    return 0;
}