// ans.cpp 24 May 17, 18:59:20 70 0 Judging completed in 5.066s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll a){
	ll b=floor(sqrt(a))+1;
	for(ll x=2;x<b;x++){
		if(a%x==0)return false;
	}
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,d;
    cin>>a;
    if(isprime(a)){
    	cout<<a<<'^'<<1;
    	return 0;
    }
    b=floor(sqrt(a))+1;
    for(ll x=2;(x<b && a>1);x++){
        if(isprime(x)){
            d=0;
            while(a%x==0){
                a/=x;
                d++;
            }
            if(d!=0){
                cout<<x<<'^'<<d;
                if(a!=1)cout<<'\n';
            }
        }
    }
    return 0;
}