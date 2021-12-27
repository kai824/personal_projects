// ans.cpp 24 Oct 17, 20:48:02 52 7.98 Judging completed in 15.653s on AWS Oregon.
#include "potatomine.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isActive(ll n){
    if(n<5000000){
        if((n%2)==0 && n!=2)return false;
        for(ll x=3;(x*x)<=n;x+=2){
            if((n%x)==0)return false;
        }
        return true;
    }
	for(int x=2;x<5000000;x++){
		if((n%x)==0)return false;
	}
	return true;
}