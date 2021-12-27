// ans.cpp 17 Nov 17, 17:20:48 21 1.94 Judging completed in 6.565s on AWS Oregon.
#include<iostream>
using namespace std;
long long ft[1000005],n,q,k,a,b,c;

long long query(long long p) {
	long long sum = 0;
	for(; p; p -= p&(-p)){
	    sum+=ft[p];sum%=k;
	}
	return sum;
}
void update(long long p, long long v) {
    v%=k;
	for(; p <= n; p += p&(-p)){
		ft[p] += v;//n is the number of elements
		ft[p]%=k;
	}
}

int main(){
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
	return 0;
}