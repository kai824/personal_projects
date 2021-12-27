// ans.cpp 14 Oct 17, 11:13:08 99 7.97 Judging completed in 13.516s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll u;
bool isActive(ll n){
    if((n%2)==0 && n!=2)return false;
    for(ll x=3;(x*x)<=n;x+=2){
        if((n%x)==0)return false;
    }
    return true;
}