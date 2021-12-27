// ans.cpp 14 Oct 17, 11:08:41 52 7.98 Judging completed in 11.844s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll u;
bool isActive(ll n){
    for(ll x=2;(x*x)<=n;x++){
        if(n%x==0)return false;
    }
    return true;
}