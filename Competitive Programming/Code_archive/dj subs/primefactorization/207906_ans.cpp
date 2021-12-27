// ans.cpp 24 May 17, 19:02:16 60 0 Judging completed in 4.326s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll a){
	for(ll x=2;x<a;x++){
		if(a%x==0)return false;
		if(x*x>a)break;
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
    for(ll x=2;(x<a && a>1);x++){
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