// ans.cpp 14 Oct 17, 11:08:24 0 0 Compilation failed on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll u;
bool isActive(ll n){
    for(ll x=2;(x*x)=<n;x++){
        if(n%x==0)return false;
    }
    return true;
}