// ans.cpp 4 Nov 17, 13:01:04 100 0.02 Judging completed in 5.272s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> primes;
bool isprime(ll a){
	for(ll x=0;x<primes.size();x++){
		if(a%primes[x]==0)return false;
		if(primes[x]*primes[x]>a)break;
	}
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,d,original;
    cin>>a;
    original=a;
    for(ll x=2;(x<=a && a!=1);x++){
    	if(x*x>a){
    		if(a==original)break;
    	}
        if(isprime(x)){
            primes.push_back(x);
            d=0;
            while(a%x==0){
                a/=x;
                d++;
            }
            if(d!=0){
                cout<<x<<'^'<<d<<'\n';
            }
        }
    }
    if(a!=1){
        cout<<a<<'^'<<1;
    }
    return 0;
}