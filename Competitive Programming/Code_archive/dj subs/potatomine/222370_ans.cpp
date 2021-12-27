// ans.cpp 14 Oct 17, 11:11:17 0 7.96 Judging completed in 12.631s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll u;
bool isActive(ll n){
    if((n%2)==0)return false;
    for(ll x=3;(x*x)<=n;x+=2){
        if((n%x)==0)return false;
    }
    return true;
}