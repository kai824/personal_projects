// ans.cpp 10 Sep 17, 21:40:04 30 0.1 Judging completed in 5.627s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int limit,a,n;
	bool b;
	limit=1300000;//all the primes within?
	vector<int>primes;
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