// ans.cpp 17 Nov 17, 17:19:02 21 1.78 Judging completed in 7.061s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long int ft[1000005],n,q,k,a,b,c;

long long int query(long long int p) {
	long long int sum = 0;
	for(; p; p -= p&(-p))sum+=ft[p];
	return sum;
}
void update(long long int p, long long int v) {
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
	        cout<<query(b)%k<<endl;
	    }
	}
	return 0;
}