// ans.cpp 18 Nov 17, 09:54:14 100 0.86 Judging completed in 15.328s on AWS Oregon.
#include<iostream>
using namespace std;
long long ft[1000005],n,q,k,a,b,c,k2;

long long ls(long long x){
    return x & -x;
}

long long query(long long p) {
	long long sum = 0;
	for(; p; p -= ls(p) ){
	    sum=(sum+ft[p])%k;
	}
	return sum;
}
void update(long long p, long long v) {
	for(; p <= n; p += ls(p)){
		ft[p]=(ft[p]+v)%k;
	}
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>q>>k2;
	k=1LL<<k2;
	for(int x=0;x<q;x++){
	    cin>>a>>b;
	    if(a==0){
	        cin>>c;
	        update(b,c);
	    }else{
	        cout<<query(b)<<'\n';
	    }
	}
}