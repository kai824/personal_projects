// ans.cpp 20 Oct 17, 14:01:32 100 0.43 Judging completed in 9.771s on AWS Oregon.
#include "blanket.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mnx=INT_MAX,mxx=INT_MIN,mny=INT_MAX,mxy=INT_MIN;
    //min-x   ,   max-x   ,   min-y   ,  max-y
long long int blanketSize(int n, int x[], int y[]) {
    for(int i=0;i<n;i++){
        if(x[i]>mxx)mxx=x[i];
        if(x[i]<mnx)mnx=x[i];
        if(y[i]<mny)mny=y[i];
        if(y[i]>mxy)mxy=y[i];
    }
    return ((mxx-mnx)*(mxy-mny));
}