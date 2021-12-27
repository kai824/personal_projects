// ans.cpp 14 Nov 17, 21:47:03 99 7.98 Judging completed in 12.261s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll myprimes[30]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

ll m;
ll ipow(ll a,ll b){
    ll ans=1,current,p=4294967296;
    for(ll x=31;(x>=0&&b>0);x--){
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
    m=n;
    for(int x=0;x<5;x++){
        if(n==myprimes[x])return true;
        if(n<myprimes[x])return false;
        if(ipow(myprimes[x],n-1)!=1)return false;
    }
    return true;
}