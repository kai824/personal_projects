// ans.cpp 7 Oct 17, 22:17:12 0 8.01 Judging completed in 12.005s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll u;
bool isActive(ll n){
    char sieve[n+1];
    for(ll x=0;x<=n;x++){sieve[x]='n';}
    for(ll x=2;x<=n;x++){
        if(sieve[x]=='n'){
            u=x;
            while(u<=n){
                sieve[u]='o';
                u+=x;
            }
            sieve[x]='y';
        }
    }
    return(sieve[n]=='y');
}