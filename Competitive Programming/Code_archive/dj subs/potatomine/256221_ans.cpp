// ans.cpp 14 Nov 17, 21:37:32 18 7.96 Judging completed in 11.953s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll myprimes[30]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

ll m;
ll ipow(ll a,ll b){//2305843009213693952
    ll ans=1,current,p=2305843009213693952;
    for(ll x=60;(x>=0&&b>0);x--){
        p/=2;
        current=a;
        if(p>b)continue;
        for(int y=0;y<x;y++){
            current=current*current;
            current%=m;
        }
        current%=m;
        ans*=current;
        ans%=m;
        b-=p;
    }
    return(ans%m);
}

bool isActive(ll n){
    if(n==1)return true;
    for(int x=0;x<30;x++){
        if(n==myprimes[x])return true;
        if(n<myprimes[x])return false;
        m=myprimes[x];
        if(ipow(n,myprimes[x]-1)!=1)return false;
    }
    return true;
}