// ans.cpp 8 Feb 17, 20:54:09 21 1 Judging completed in 6.454s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
int ft[1000005],n,q,k,a,b,c;
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(int p, int v) {
    v%=k;
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
		ft[p]%=k;
	}
}
int main(){
	cin>>n>>q>>k;
	k=pow(2,k);
	for(int x=0;x<q;x++){
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