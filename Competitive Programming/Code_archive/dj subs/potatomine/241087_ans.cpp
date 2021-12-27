// ans.cpp 4 Nov 17, 14:14:52 99 7.97 Judging completed in 12.167s on AWS Oregon.
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