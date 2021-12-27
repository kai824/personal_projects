// ans.cpp 9 Oct 17, 12:23:00 52 7.96 Judging completed in 11.829s on AWS Oregon.
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