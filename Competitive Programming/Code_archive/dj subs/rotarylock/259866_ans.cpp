// ans.cpp 18 Nov 17, 09:46:37 21 1.53 Judging completed in 6.417s on AWS Oregon.
#include<iostream>
using namespace std;
long long ft[1000005],n,q,k,a,b,c;

long long query(long long p) {
	long long sum = 0;
	for(; p; p -= p&(-p)){
	    sum=(sum+ft[p])%k;
	}
	return sum;
}
void update(long long p, long long v) {
	for(; p <= n; p += p&(-p)){
		ft[p]=(ft[p]+v)%k;
	}
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>q>>k;
	k=1<<k;
	for(int x=0;x<q;x++){
	    cin>>a>>b;
	    if(a==0){
	        cin>>c;
	        update(b,c);
	    }else{
	        cout<<query(b)<<endl;
	    }
	}
}