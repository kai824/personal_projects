// ans.cpp 14 Nov 17, 21:52:22 99 3.04 Judging completed in 7.061s on AWS Oregon.
#include "potatomine.h"
using namespace std;
typedef long long ll;
ll myprimes[30]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

ll m;
ll ipow(ll base, ll exponent) { 
    ll result = 1;                        
    while (exponent) {                        // while the exponent is still non-zero
        if (exponent%2==1) result *= base;       // if the p contains the current power of 2, 
                                                   // multiply result by base^(2^current_power)

        base *= base;                            // square the base to get the next power of 2
        base %= m;                  //mod the integer, so it doesn't overflow
        result %= m;         //same concept
        exponent >>= 1;                          // remove current power of 2 
                                                            //equivalent to (exponent /= 2)
    }
    return result;
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