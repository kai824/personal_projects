// ans.cpp 10 Sep 17, 21:42:22 60 1.92 Judging completed in 6.014s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll limit,a,n;
	bool b;
	limit=5000000;//all the primes within?
	vector<ll>primes;
	a=1;
	while(true){
		a++;
		if(a>limit)break;
		b=false;
		for(int x=0;x<primes.size();x++){
			if(a%primes[x]==0){
				b=true;
				break;
			}
			if(primes[x]*primes[x]>a)break;
		}
		if(!b)primes.push_back(a);
	}
	cin>>n;
	cout<<primes[primes[n-1]-1];
	return 0;
}