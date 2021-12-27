// ans.cpp 22 Aug 17, 21:15:15 70 0.14 Judging completed in 5.547s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int limit,a,lo,hi,mid,tc,p,q;
	bool b;
	limit=1000000;//all the primes within?
	double s=clock();
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
	cin>>tc;
	for(int x=0;x<tc;x++){
		cin>>p>>q;
		lo=0;hi=primes.size()-1;
		while(lo<hi){
			mid=(hi-lo)/2+lo;
			if(primes[mid]<p){
				lo=mid+1;
			}else{//primes[mid]>=p
				hi=mid;
			}
		}
		p=lo;
		lo=0;hi=primes.size()-1;
		while(lo<hi){
			mid=(hi-lo)/2+lo;
			if(primes[mid]<=q){
				lo=mid+1;
			}else{//primes[mid]>=p
				hi=mid;
			}
		}
		q=lo;
		cout<<q-p<<'\n';
	}
	return 0;
}