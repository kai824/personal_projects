// ans.cpp 8 May 17, 13:10:04 0 0 Judging completed in 6.129s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll a){
	ll b=floor(sqrt(a))+1;
	for(ll x=2;x<b;x++){
		if(b%x==0)return false;
	}
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,d;
    cin>>a;
    b=floor(sqrt(b))+1;
    for(int x=2;(x<b && a>1);x++){
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
    return 0;
}