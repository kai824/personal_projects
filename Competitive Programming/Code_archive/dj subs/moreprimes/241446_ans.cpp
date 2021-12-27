// ans.cpp 4 Nov 17, 15:12:50 60 0.32 Judging completed in 8.828s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sieve[10000010];
bool sieve2[10000010];//sieve[0] shows whether sieve[p] is composite...
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll p,q,u;
    vector<ll>primes;
    cin>>p>>q;
    if(q<=1e7+5){
        for(int x=2;x<=q;x++){
            if(sieve[x]){//marked...
                sieve[x]=false;
            }else{//not marked...
                sieve[x]=true;
                u=x*2;
                while(u<=1e7){
                    sieve[u]=true;//mark it...
                    u+=x;
                }
                if(p<=x)cout<<x<<'\n';
            }
        }
    }else{
        
        for(ll x=2;x<=1e7+5;x++){
            if(sieve[x]){//marked...
                sieve[x]=false;
            }else{//not marked...
                sieve[x]=true;
                u=x*2;
                while(u<=1e7+5){
                    sieve[u]=true;//mark it...
                    u+=x;
                }
                primes.push_back(x);
            }
        }
        for(ll x=0;x<primes.size();x++){
        	u=p-(p%primes[x]);
        	if(u<p)u+=primes[x];
        	while(u<=q){
        	    sieve2[u-p]=true;
        	    u+=primes[x];
        	}
        }
        for(ll x=p;x<=q;x++){
            if(sieve2[x-p]=false)cout<<x<<'\n';
        }
    }
    return 0;
}