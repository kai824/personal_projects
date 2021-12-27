// ans.cpp 17 Nov 17, 16:42:51 21 1.01 Judging completed in 5.659s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll ft[1000005],n,q,k,a,b,c;
ll ls(ll x){
	return(x & (-x));
}
ll query(ll p) {
	ll sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(ll p,ll v) {
    v%=k;
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
		ft[p]%=k;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>q>>k;
	k=1<<k;
	for(ll x=0;x<q;x++){
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