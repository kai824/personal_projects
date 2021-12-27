// ans.cpp 4 Nov 17, 13:41:25 60 0.24 Judging completed in 6.679s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sieve[10000005];
bool sieve2[10000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll p,q,u;
    cin>>p>>q;
    vector<ll>primes;
    if(q<=1e7){
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
        
        for(int x=2;x<=1e7;x++){
            if(sieve[x]){//marked...
                sieve[x]=false;
            }else{//not marked...
                sieve[x]=true;
                u=x*2;
                while(u<=1e7){
                    sieve[u]=true;//mark it...
                    u+=x;
                }
                primes.push_back(x);
            }
        }
        
        
    }
    return 0;
}