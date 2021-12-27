// ans.cpp 24 May 17, 19:05:58 80 1 Judging completed in 5.066s on AWS Oregon.
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
    for(ll x=2;(x<a && a>1);x++){
        if(isprime(x)){
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