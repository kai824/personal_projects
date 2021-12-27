// ans.cpp 14 Oct 17, 11:10:15 0 7.94 Judging completed in 11.986s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll u;
bool isActive(ll n){
    if(n%2==0)return false;
    for(ll x=3;(x*x)<=n;x+=2){
        if(n%x==0)return false;
    }
    return true;
}