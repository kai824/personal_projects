// ans.cpp 8 Feb 17, 20:55:53 21 1 Judging completed in 7.125s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
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
int main(){
	cin>>n>>q>>k;
	k=pow(2,k);
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