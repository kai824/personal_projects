// ans.cpp 17 Nov 17, 17:10:35 0 1.01 Judging completed in 4.209s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long int ft[1000005],n,q,k,a,b,c;
long long int query(long long int index) {
	ll sum=0;
	index++;
	while (index>0){
	    sum += ft[index];
        index-=index & (-index);
    }
    return sum;
}
void update(long long int p, long long int v) {
    v%=k;
	for(; p <= n; p += p&-p){
		ft[p] += v;//n is the number of elements
		ft[p]%=k;
	}
}
int main(){
	cin>>n>>q>>k;
	k=1<<k;
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