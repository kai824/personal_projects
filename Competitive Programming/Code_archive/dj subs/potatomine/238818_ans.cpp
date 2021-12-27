// ans.cpp 1 Nov 17, 18:22:08 0 7.98 Judging completed in 15.785s on AWS Oregon.
#include "potatomine.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;
ll ipow(ll a,ll b){//2305843009213693952
    ll ans=1,current,p=2305843009213693952;
    for(ll x=60;(x>=0&&b>0);x--){
        p/=2;
        current=a;
        if(p>b)continue;
        for(int y=0;y<x;y++){
            current=current*current;
            current%=mod;
        }
        current%=mod;
        ans*=current;
        ans%=mod;
        b-=p;
    }
    return(ans%mod);
}

ll m,k,a=2,p;
bool first=true;
bool isActive(ll n){//isPrime
    if(n==2)return true;
    else if(n==1)return false;
    set<int> ss;
    m=n-1;
    while(true){
        if(m%2==0){
            m/=2;
            k++;
        }else break;
    }
    mod=n;
    p=ipow(a,m);
    while(true){
        if(p==1 || p==n-1){
            if(first==true){
                return true;
            }else{
                if(p==n-1){
                    return true;
                }else{
                    return false;
                }
            }
            break;
        }
        first=false;
        ss.insert(p);
        p=(p*p)%n;
        if(ss.find(p)!=ss.end()){
        	return false;
        }
    }
}