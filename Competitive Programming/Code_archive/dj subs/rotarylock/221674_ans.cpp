// ans.cpp 7 Oct 17, 21:15:44 21 2.98 Judging completed in 8.57s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long int ft[1000005],n,q,k,a,b,c;
long long int ls(long long int x){
	return(x & (-x));
}
long long int query(long long int p) {
	long long int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(long long int p, long long int v) {
    v%=k;
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
		ft[p]%=k;
	}
}
long long ipow(ll a,ll b){
    ll ans=1;
    for(ll x=0;x<b;x++){
        ans*=a;
    }
    return ans;
}
int main(){
	cin>>n>>q>>k;
	k=ipow(2,k);
	for(long long int x=0;x<q;x++){
	    cin>>a>>b;
	    if(a==0){
	        cin>>c;
	        update(b,c);
	    }else{
	        cout<<query(b)%k<<endl;
	    }
	}
	return 0;
}