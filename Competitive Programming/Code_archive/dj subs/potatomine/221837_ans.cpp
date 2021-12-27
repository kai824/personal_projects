// ans.cpp 9 Oct 17, 12:24:13 52 7.98 Judging completed in 12.586s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll u;
bool isActive(ll n){
    for(ll x=2;x<n;x++){
        if(n%x==0)return false;
        if(x*x>n)break;
    }
    return true;
}