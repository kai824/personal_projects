// ans.cpp 13 Oct 17, 10:32:21 60 1.01 Judging completed in 5.93s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll limit=10000005,lo,hi,mid;
bool sieve[10000005],b;//false for not prime, true for prime...
vector<ll> primes;//primes under limit...
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll p,q,u;
    cin>>p>>q;
    if(p>q)swap(p,q);
    for(ll x=2;x<limit;x++){
        if(sieve[x]==true){//if it was marked before, it is not prime anymore...
            sieve[x]=false;
            continue;
        }
        u=x;
        while(u<limit){
            sieve[u]=true;
            u+=x;
        }
        primes.push_back(x);
    }
    for(ll x=p;x<=q;x++){
        //checking if x is prime, continue if not prime
        if(x<limit){
            if(sieve[x]==false)continue;
        }else{
            b=false;
            for(ll y=0;y<primes.size();y++){
                if((x%primes[y])==0){
                    b=true;
                    break;
                }
                if(primes[y]*primes[y]>x)break;
            }
            if(b)continue;
        }
        cout<<x<<'\n';
    }
    return 0;
}